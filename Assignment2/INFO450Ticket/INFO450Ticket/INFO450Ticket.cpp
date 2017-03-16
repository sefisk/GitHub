// INFO450Ticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class SystemTicket
{
protected:
	int ID;
	int getPriority;
	string Ticket_ID, FullName, getType, getDescription, getImpact, TicketStatus, Priority;
public:

	SystemTicket() {};
	SystemTicket(string t, string a, string c, string i, string e)
	{
		FullName = t; getType = a;
		getImpact = c; getDescription = i;
		Ticket_ID = e;

	}
	virtual void Display() = 0;
	virtual void CaptureData() {};
	virtual string SetStatus(string a) = 0;
	virtual string GetInformation(string a) = 0;
};

class Ticket : public SystemTicket
{
public:
	Ticket() {};
	Ticket(string t, string a, string c, string i, string e) : SystemTicket(t, a, c, i, e)
	{
	}
	void Display();
	void CaptureData();
	string SetStatus(string a);
	string GetInformation(string a);
};

void Ticket::CaptureData()
{
	cin.ignore();
	cin.clear();
	cout << "Name of the Caller: ";
	getline(cin, FullName);
	cout << endl << "Issue Type? S=Server, A=Application, C=Access" << endl;
	getline(cin, getType);
	cout << "Please give a description of the problem: " << endl;
	getline(cin, getDescription);
	cout << endl << "How many users does this impact?" << endl;
	cin >> getPriority;
	if ((getPriority > 25) && (getPriority < 50)) {
		Priority = "Medium";
	}
	else if ((getPriority >= 50) && (getPriority <= 100)) {
		Priority = "High";
	}
	else { Priority = "Low"; }

}
string Ticket::SetStatus(string a)
{
	TicketStatus = a;
	return TicketStatus;
}
string Ticket::GetInformation(string a)
{
	Ticket_ID = a;
	return Ticket_ID;
}

void Ticket::Display()
{
	cout << "Ticket Identification: " << Ticket_ID << endl;
	cout << "Customers Full Name: " << FullName << endl;
	cout << "Service Issue: " << getType << endl;
	cout << "Ticket Status: " << Priority << endl;
	cout << "How many users impacted: " << getPriority << endl;
	cout << "Description: " << endl;
	cout << getDescription << endl << endl;

}

int main()
{
	SystemTicket **plist;
	int count;
	char ptype;
	bool isOver = false;

	cout << "How Many Entries?" << endl;
	cin >> count;

	plist = new SystemTicket*[count];

	for (int i = 0; i < count; i++)
	{

		plist[i] = new Ticket();


		plist[i]->CaptureData();
		plist[i]->SetStatus("Open");
		string s = to_string(i);
		plist[i]->GetInformation(s);
		plist[0]->SetStatus("Closed");
		cout << endl << "Another User? Y/N?" << endl;
		cin >> ptype;
		if (toupper(ptype) == 'Y')
		{
			continue;
		}
		else if (toupper(ptype) == 'N')
		{
			count = i + 1;
			isOver = true;
			break;
		}
	}
	if (isOver == true) {
		//Extra credit

	}


	for (int i = 0; i < count; i++)
	{
		plist[i]->Display();
		cout << endl;
	}

	for (int i = 0; i < count; i++)
	{
		delete plist[i];
	}
	delete plist;

	return 0;
}