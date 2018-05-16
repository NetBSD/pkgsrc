$NetBSD: patch-calendar_gui_e-meeting-store.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/e-meeting-store.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/e-meeting-store.c
@@ -1072,7 +1072,7 @@ process_free_busy_comp (EMeetingAttendee
 		icaltimezone *ds_zone;
 
 		dtstart = icalproperty_get_dtstart (ip);
-		if (!dtstart.is_utc)
+		if (!icaltime_is_utc(dtstart))
 			ds_zone = find_zone (ip, tz_top_level);
 		else
 			ds_zone = icaltimezone_get_utc_timezone ();
@@ -1091,7 +1091,7 @@ process_free_busy_comp (EMeetingAttendee
 		icaltimezone *de_zone;
 
 		dtend = icalproperty_get_dtend (ip);
-		if (!dtend.is_utc)
+		if (!icaltime_is_utc(dtend))
 			de_zone = find_zone (ip, tz_top_level);
 		else
 			de_zone = icaltimezone_get_utc_timezone ();
