$NetBSD: patch-calendar_gui_itip-utils.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/itip-utils.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/itip-utils.c
@@ -1115,7 +1115,7 @@ comp_compliant (ECalComponentItipMethod
 			r->until.is_date = FALSE;
 
 			icaltimezone_convert_time (&r->until, from_zone, to_zone);
-			r->until.is_utc = TRUE;
+			r->until.zone = icaltimezone_get_utc_timezone();
 
 			e_cal_component_free_datetime (&dt);
 			e_cal_component_set_rrule_list (clone, rrule_list);
