$NetBSD: patch-gnucash_gnome_assistant-loan.cpp,v 1.3 2025/07/13 18:15:53 wiz Exp $

https://github.com/Gnucash/gnucash/commit/d0e7b83d364228ee9c2e7ca1d98e2cc21f56fbcd

--- gnucash/gnome/assistant-loan.cpp.orig	2025-07-13 18:14:36.766834508 +0000
+++ gnucash/gnome/assistant-loan.cpp
@@ -2393,7 +2393,7 @@ std::string to_str_with_prec (const gdou
 #endif
 }
 
-static constexpr std::tuple<double, double>
+static std::tuple<double, double>
 periods_per_year( LoanAssistantData *ldd)
 {
     double ppy = 0.0, periods = 1.0;
