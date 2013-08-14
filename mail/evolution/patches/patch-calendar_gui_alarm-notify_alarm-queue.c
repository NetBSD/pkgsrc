$NetBSD: patch-calendar_gui_alarm-notify_alarm-queue.c,v 1.1 2013/08/14 04:35:32 obache Exp $

* for libnotify-0.7

--- calendar/gui/alarm-notify/alarm-queue.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/gui/alarm-notify/alarm-queue.c
@@ -1606,7 +1606,7 @@ popup_notification (time_t trigger, Comp
 			body = g_strdup_printf ("%s %s", start_str, time_str);
 	}
 
-	n = notify_notification_new (summary, body, "stock_appointment-reminder", NULL);
+	n = notify_notification_new (summary, body, "stock_appointment-reminder");
 	if (!notify_notification_show(n, NULL))
 	    g_warning ("Could not send notification to daemon\n");
 
