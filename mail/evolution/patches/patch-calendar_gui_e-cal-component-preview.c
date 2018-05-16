$NetBSD: patch-calendar_gui_e-cal-component-preview.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/e-cal-component-preview.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/e-cal-component-preview.c
@@ -143,7 +143,7 @@ timet_to_str_with_zone (ECalComponentDat
 		/* If we can't find the zone, we'll guess its "local" */
 		if (!e_cal_get_timezone (ecal, dt->tzid, &zone, NULL))
 			zone = NULL;
-	} else if (dt->value->is_utc) {
+	} else if (icaltime_is_utc(*dt->value)) {
 		zone = icaltimezone_get_utc_timezone ();
 	} else {
 		zone = NULL;
