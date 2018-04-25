$NetBSD: patch-calendar_libecal_e-cal-time-util.c,v 1.1 2018/04/25 05:57:58 markd Exp $

work with libical-3

--- calendar/libecal/e-cal-time-util.c.orig	2011-04-21 19:35:36.000000000 +0000
+++ calendar/libecal/e-cal-time-util.c
@@ -724,7 +724,6 @@ tm_to_icaltimetype (struct tm *tm, gbool
 	itt.month = tm->tm_mon + 1;
 	itt.year = tm->tm_year+ 1900;
 
-	itt.is_utc = 0;
 	itt.is_date = is_date;
 
 	return itt;
