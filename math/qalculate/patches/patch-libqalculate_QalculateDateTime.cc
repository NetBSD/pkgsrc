$NetBSD: patch-libqalculate_QalculateDateTime.cc,v 1.1 2024/03/11 09:45:32 jperkin Exp $

Avoid sun define.

--- libqalculate/QalculateDateTime.cc.orig	2024-03-11 09:42:35.031529108 +0000
+++ libqalculate/QalculateDateTime.cc
@@ -2026,8 +2026,8 @@ Number chinese_new_moon_before(Number da
 	return ret;
 }
 Number chinese_solar_longitude_on_or_after(Number lam, Number tee) {
-	Number sun = solar_longitude_after(lam, universal_from_standard(tee, chinese_zone(tee)));
-	return standard_from_universal(sun, chinese_zone(sun));
+	Number s = solar_longitude_after(lam, universal_from_standard(tee, chinese_zone(tee)));
+	return standard_from_universal(s, chinese_zone(s));
 }
 Number current_major_solar_term(Number date) {
 	Number s = solar_longitude(universal_from_standard(date, chinese_zone(date)));
