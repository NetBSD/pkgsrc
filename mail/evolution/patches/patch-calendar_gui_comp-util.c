$NetBSD: patch-calendar_gui_comp-util.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/comp-util.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/comp-util.c
@@ -127,8 +127,8 @@ cal_comp_util_compare_event_timezones (E
 	/* If the event uses UTC for DTSTART & DTEND, return TRUE. Outlook
 	   will send single events as UTC, so we don't want to mark all of
 	   these. */
-	if ((!start_datetime.value || start_datetime.value->is_utc)
-	    && (!end_datetime.value || end_datetime.value->is_utc)) {
+	if ((!start_datetime.value || icaltime_is_utc(*start_datetime.value))
+	    && (!end_datetime.value || icaltime_is_utc(*end_datetime.value))) {
 		retval = TRUE;
 		goto out;
 	}
