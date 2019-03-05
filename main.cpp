#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "person.h"
using namespace std;

void readFile(vector<Person> &employees);
void getCompanies(vector<Person> &employees, vector<string> &companyNames);
void printHighestPaid(vector<Person> &employees);
void separateAndSave(vector<Person> &employees, vector<string> &companyNames);

int main() {
	vector<Person> employees;
	vector<string> companyNames;

	readFile(employees);
	getCompanies(employees, companyNames);
	printHighestPaid(employees);
	separateAndSave(employees, companyNames);
}

void readFile(vector<Person> &employees)
{
	fstream inFile;
	inFile.open("input.txt");

	string fName, lName, company;
	int ID;
	float hours, rate;

	Person employee;
	inFile >> fName;

	int i = 0;
	while(!inFile.eof()) {
		inFile >> lName >> ID >> company >> hours >> rate >> fName;

		employee.setCompanyName(company);
		employee.setEmployeeId(ID);
		employee.setFirstName(fName);
		employee.setHoursWorked(hours);
		employee.setPayRate(rate);
		employee.setLastName(lName);

		employees.push_back(employee);
	}

	// for (int i = 0; i < employees.size(); i++) {
	// 	cout << employees.at(i).getFirstName() << endl;
	// }

	inFile.close();
}
void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
	for (int i = 0; i < employees.size(); i++) {
		companyNames.push_back(employees.at(i).getCompanyName());

		//cout << companyNames.at(i) << endl;
	}
}

void printHighestPaid(vector<Person> &employees)
{
	Person highest = employees.at(0);
	float pay = employees.at(0).totalPay();
	//cout << pay << endl;

	for (int i = 0; i < employees.size(); i++) {
		if (employees.at(i).totalPay() > pay) {
			highest = employees.at(i);

			// highest.setEmployeeId(it->getEmployeeId());
			// highest.setCompanyName(it->getCompanyName());
			// highest.setFirstName(it->getFirstName());
			// highest.setLastName(it->getLastName());
			// highest.setPayRate(it->getPayRate());
			// highest.setHoursWorked(it->getHoursWorked());
		}
	}

	cout << "Highest paid: " << highest.getFirstName() << " " << highest.getLastName() << endl;
	cout << "Employee ID: " << highest.getEmployeeId() << endl;
	cout << "Employer: " << highest.getCompanyName() << endl;
	cout << "Total pay: $" << highest.totalPay() << endl;

	cout << endl << endl;
}

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
	for (int i = 0; i < companyNames.size(); i++) 
	{
		int companyTotal = 0.00;
		cout << companyNames.at(i) << ".txt" << endl;
		cout << "-----------------------------------------" << endl;
		for (int j = 0; j < employees.size(); j++) 
		{
			if (employees.at(j).getCompanyName() == companyNames.at(i)) {
				cout << left << setw(8) << employees.at(j).getFirstName() << " " << setw(9) << employees.at(j).getLastName() << " " << setw(3) << employees.at(j).getEmployeeId() << " " << setw(8) << employees.at(j).getCompanyName() << " " << fixed << setprecision(2) << employees.at(j).totalPay() << endl;
				companyTotal += employees.at(j).totalPay();
			}
		}
		cout << "Total $" << companyTotal << endl << endl;
	}
}