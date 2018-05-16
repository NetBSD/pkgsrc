$NetBSD: patch-calendar_gui_gnome-cal.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/gnome-cal.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/gnome-cal.c
@@ -743,13 +743,13 @@ ensure_dates_are_in_default_zone (GnomeC
 		return;
 
 	dt = icalcomponent_get_dtstart (icalcomp);
-	if (dt.is_utc) {
+	if (icaltime_is_utc(dt)) {
 		dt = icaltime_convert_to_zone (dt, timezone);
 		icalcomponent_set_dtstart (icalcomp, dt);
 	}
 
 	dt = icalcomponent_get_dtend (icalcomp);
-	if (dt.is_utc) {
+	if (icaltime_is_utc(dt)) {
 		dt = icaltime_convert_to_zone (dt, timezone);
 		icalcomponent_set_dtend (icalcomp, dt);
 	}
