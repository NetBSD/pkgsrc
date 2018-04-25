$NetBSD: patch-calendar_libecal_e-cal-recur.c,v 1.1 2018/04/25 05:57:58 markd Exp $

work with libical-3

--- calendar/libecal/e-cal-recur.c.orig	2011-04-21 19:35:36.000000000 +0000
+++ calendar/libecal/e-cal-recur.c
@@ -3738,10 +3738,7 @@ cal_object_time_from_time	(CalObjTime	*c
 {
 	struct icaltimetype tt;
 
-	if (zone)
-		tt = icaltime_from_timet_with_zone (t, FALSE, zone);
-	else
-		tt = icaltime_from_timet (t, FALSE);
+	tt = icaltime_from_timet_with_zone (t, FALSE, zone);
 
 	cotime->year     = tt.year;
 	cotime->month    = tt.month - 1;
