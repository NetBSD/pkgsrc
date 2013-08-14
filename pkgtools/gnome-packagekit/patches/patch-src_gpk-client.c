$NetBSD: patch-src_gpk-client.c,v 1.1 2013/08/14 05:31:04 obache Exp $

* for libnotify-0.7 API change

--- src/gpk-client.c.orig	2008-12-09 08:22:40.000000000 +0000
+++ src/gpk-client.c
@@ -298,7 +298,7 @@ gpk_client_finished_no_progress (PkClien
 	}
 
 	/* TRANSLATORS: title: system update completed all okay */
-	notification = notify_notification_new (_("The system update has completed"), message_text->str, "help-browser", NULL);
+	notification = notify_notification_new (_("The system update has completed"), message_text->str, "help-browser");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	if (restart == PK_RESTART_ENUM_SYSTEM) {
@@ -501,7 +501,7 @@ gpk_client_error_code_cb (PkClient *clie
 	gclient->priv->error_details = g_markup_escape_text (details, -1);
 
 	/* do the bubble */
-	notification = notify_notification_new (title, message, "help-browser", NULL);
+	notification = notify_notification_new (title, message, "help-browser");
 	notify_notification_set_timeout (notification, 15000);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	notify_notification_add_action (notification, "show-error-details",
@@ -2853,7 +2853,7 @@ gpk_client_update_system (GpkClient *gcl
 		notification = notify_notification_new (_("Updates are being installed"),
 							/* TRANSLATORS: tell the user why the hard disk is grinding... */
 							_("Updates are being automatically installed on your computer"),
-							"software-update-urgent", NULL);
+							"software-update-urgent");
 		notify_notification_set_timeout (notification, 15000);
 		notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 		/* TRANSLATORS: button: cancel the update system */
