#pragma once
#include <string>
#include <memory>
#include <map>
#include <vector>
#include "cwMarketTime.h"



class cwProductTradeTime
{

public:
	cwProductTradeTime();
	~cwProductTradeTime();

	enum cwTradeTimeSpace
	{
		NoTrading = 0
		, AMPartOne
		, AMPartTwo
		, PMPartOne
		, NightPartOne
	};

	typedef struct tagProductTradeTime
	{
		cwTradeTimeSpace TradeTimeSpace;

		cwMarketTimePtr BeginTime;
		cwMarketTimePtr EndTime;

	}ProductTradeTime;
	typedef std::shared_ptr<ProductTradeTime> TradeTimePtr;

	bool GetTradeTimeSpace(std::string ProductId, std::string updatetime,
		cwTradeTimeSpace& iTradeIndex, int& iOpen, int& iClose);
private:
	std::map<std::string, std::vector<TradeTimePtr>> m_ProductTradeTimeMap;
	void InitialTradeTimeMap();
};

