$NetBSD: patch-util.c,v 1.1 2012/01/02 07:35:22 pettai Exp $

Fixes the bug in ldns_year_and_yday_from_days_since_epoch on 32-bit OSes
http://open.nlnetlabs.nl/pipermail/ldns-users/2011-December/000452.html
(patch taken from trunk)

--- util.c.orig	2012-01-01 23:16:59.000000000 +0000
+++ util.c
@@ -256,10 +256,7 @@ ldns_year_and_yday_from_days_since_epoch
 	int new_year;
 
 	while (days < 0 || days >= (int64_t) (is_leap_year(year) ? 366 : 365)) {
-		new_year = year + (int) LDNS_DIV(days, 366);
-		if (year == new_year) {
-			year += days < 0 ? -1 : 1;
-		}
+		new_year = year + (int) LDNS_DIV(days, 365);
 		days -= (new_year - year) * 365;
 		days -= leap_days(year, new_year);
 		year  = new_year;
