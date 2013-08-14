$NetBSD: patch-plugins_mail-notification_mail-notification.c,v 1.1 2013/08/14 04:35:32 obache Exp $

* for libnotify-0.7

--- plugins/mail-notification/mail-notification.c.orig	2011-03-29 18:38:48.000000000 +0000
+++ plugins/mail-notification/mail-notification.c
@@ -564,9 +564,7 @@ new_notify_status (EMEventTargetFolder *
 
 			notify  = notify_notification_new (
 				_("New email"), safetext,
-				"mail-unread", NULL);
-			notify_notification_attach_to_status_icon (
-				notify, status_icon);
+				"mail-unread");
 
 			/* Check if actions are supported */
 			if (can_support_actions ()) {
