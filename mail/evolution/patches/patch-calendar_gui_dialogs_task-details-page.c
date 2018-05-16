$NetBSD: patch-calendar_gui_dialogs_task-details-page.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/gui/dialogs/task-details-page.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/dialogs/task-details-page.c
@@ -341,7 +341,7 @@ task_details_page_fill_component (CompEd
 	icalcomplete = icaltime_null_time ();
 
 	/* COMPLETED must be in UTC. */
-	icalcomplete.is_utc = 1;
+	icalcomplete.zone = icaltimezone_get_utc_timezone();
 
 	/* Completed Date. */
 	if (!e_date_edit_date_is_valid (E_DATE_EDIT (priv->completed_date)) ||
@@ -503,7 +503,7 @@ complete_date_changed (TaskDetailsPage *
 	/* Get the current time in UTC. */
 	zone = icaltimezone_get_utc_timezone ();
 	completed_tt = icaltime_from_timet_with_zone (ctime, FALSE, zone);
-	completed_tt.is_utc = TRUE;
+	completed_tt.zone = icaltimezone_get_utc_timezone();
 
 	dates.start = NULL;
 	dates.end = NULL;
