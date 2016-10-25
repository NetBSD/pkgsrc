$NetBSD: patch-res_res__calendar__icalendar.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- res/res_calendar_icalendar.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ res/res_calendar_icalendar.c
@@ -246,7 +246,7 @@ static void icalendar_add_event(icalcomp
 			ast_string_field_set(event, uid, event->summary);
 		} else {
 			char tmp[100];
-			snprintf(tmp, sizeof(tmp), "%ld", event->start);
+			snprintf(tmp, sizeof(tmp), "%jd", (intmax_t)event->start);
 			ast_string_field_set(event, uid, tmp);
 		}
 	}
