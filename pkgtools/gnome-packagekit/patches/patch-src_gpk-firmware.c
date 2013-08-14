$NetBSD: patch-src_gpk-firmware.c,v 1.1 2013/08/14 05:31:04 obache Exp $

* for libnotify-0.7 API change

--- src/gpk-firmware.c.orig	2008-11-24 16:33:50.000000000 +0000
+++ src/gpk-firmware.c
@@ -198,7 +198,7 @@ gpk_firmware_timeout_cb (gpointer data)
 	/* TRANSLATORS: we need another package to keep udev quiet */
 	message = _("Additional firmware is required to make hardware in this computer function correctly.");
 	/* TRANSLATORS: title of libnotify bubble */
-	notification = notify_notification_new (_("Additional firmware required"), message, "help-browser", NULL);
+	notification = notify_notification_new (_("Additional firmware required"), message, "help-browser");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, "install-firmware",
