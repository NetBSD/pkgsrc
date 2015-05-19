$NetBSD: patch-res_res__calendar__icalendar.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- res/res_calendar_icalendar.c.orig	2014-05-09 22:28:40.000000000 +0000
+++ res/res_calendar_icalendar.c
@@ -245,7 +245,7 @@ static void icalendar_add_event(icalcomp
 			ast_string_field_set(event, uid, event->summary);
 		} else {
 			char tmp[100];
-			snprintf(tmp, sizeof(tmp), "%ld", event->start);
+			snprintf(tmp, sizeof(tmp), "%jd", (intmax_t)event->start);
 			ast_string_field_set(event, uid, tmp);
 		}
 	}
