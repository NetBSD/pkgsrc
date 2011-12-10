$NetBSD: patch-kmymoney2_mymoney_mymoneymoney.cpp,v 1.1 2011/12/10 17:50:23 marino Exp $

--- kmymoney2/mymoney/mymoneymoney.cpp.orig	2010-03-02 09:45:39.000000000 +0000
+++ kmymoney2/mymoney/mymoneymoney.cpp
@@ -46,9 +46,9 @@ bool MyMoneyMoney::_positivePrefixCurren
 
 MyMoneyMoney::fileVersionE MyMoneyMoney::_fileVersion = MyMoneyMoney::FILE_4_BYTE_VALUE;
 
-MyMoneyMoney MyMoneyMoney::maxValue = MyMoneyMoney(INT64_MAX,100);
-MyMoneyMoney MyMoneyMoney::minValue = MyMoneyMoney(INT64_MIN,100);
-MyMoneyMoney MyMoneyMoney::autoCalc = MyMoneyMoney(INT64_MIN+1,100);
+MyMoneyMoney MyMoneyMoney::maxValue = MyMoneyMoney((signed64)INT64_MAX,100);
+MyMoneyMoney MyMoneyMoney::minValue = MyMoneyMoney((signed64)INT64_MIN,100);
+MyMoneyMoney MyMoneyMoney::autoCalc = MyMoneyMoney((signed64)INT64_MIN+1,100);
 
 void MyMoneyMoney::setNegativePrefixCurrencySymbol(const bool flag)
 {
