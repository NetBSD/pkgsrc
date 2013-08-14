$NetBSD: patch-src_gpk-hardware.c,v 1.1 2013/08/14 05:31:04 obache Exp $

* for libnotify-0.7 API change

--- src/gpk-hardware.c.orig	2008-11-24 16:33:50.000000000 +0000
+++ src/gpk-hardware.c
@@ -162,7 +162,7 @@ gpk_hardware_check_for_driver_available 
 	message = g_strdup_printf ("%s\n\t%s", _("Additional packages can be installed to support this hardware"), package);
 	/* TRANSLATORS: a new bit of hardware has been plugged in */
 	body = g_strdup_printf ("%s", _("New hardware attached"));
-	notification = notify_notification_new (body, message, "help-browser", NULL);
+	notification = notify_notification_new (body, message, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, GPK_HARDWARE_INSTALL_ACTION,
