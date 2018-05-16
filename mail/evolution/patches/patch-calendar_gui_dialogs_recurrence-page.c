$NetBSD: patch-calendar_gui_dialogs_recurrence-page.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/dialogs/recurrence-page.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/dialogs/recurrence-page.c
@@ -1516,7 +1516,7 @@ fill_ending_date (RecurrencePage *rpage,
 				r->until.minute = 0;
 				r->until.second = 0;
 				r->until.is_date = TRUE;
-				r->until.is_utc = FALSE;
+				r->until.zone = icaltimezone_get_utc_timezone();
 
 				e_cal_component_free_datetime (&dt);
 			}
