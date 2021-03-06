/*
 * GraphCreater.h
 *
 *  Created on: 24/04/2015
 *      Author: Rui
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <string>
#include <utility>

using namespace std;

class Street;
class Graph;

class InterestPoint {
	string name;
	pair<double, double> coords;
	vector<Street> conections;
	bool visited;
public:

	InterestPoint(string name, pair<double, double> coords);
	friend class Graph;

	void addStreet(InterestPoint *dest, double distance);
	bool removeStreetTo(InterestPoint *dest);

	string getName() const;
	pair<double, double> getCoords();
	void setName(string name);
	vector<Street> getConections();
	bool isVisited();
};

class Street {
	InterestPoint* dest;
	double distance;
public:
	Street(InterestPoint* ip, double distance);
	friend class InterestPoint;
	friend class Graph;
};

class Graph {
	vector<InterestPoint*> listIP;
	pair<double, double> limitsLatitude;
	pair<double, double> limitsLongitude;

	void initialize();
	void reorderLimits();
	void setLimits(const pair<double, double>& coords);

public:
	Graph();
	bool addInterestPoint(const string &ip, pair<double, double> coords);
	bool addStreet(const string &src, const string &dest, double distance);
	bool removeInterestPoint(const string &ip);
	bool removeStreet(const string &src, const string &dest);

	vector<InterestPoint*> getListIp();
	pair<double, double> getLimitsLatitude();
	pair<double, double> getLimitsLongitude();
};

#endif /* GRAPH_H_ */
