$NetBSD: patch-src_gpm-notify.c,v 1.1 2013/08/14 08:01:48 obache Exp $

* for libnotify-0.7 API change

--- src/gpm-notify.c.orig	2008-09-04 10:05:15.000000000 +0000
+++ src/gpm-notify.c
@@ -103,14 +103,7 @@ gpm_notify_create (GpmNotify 	 *notify,
 //		notify->priv->libnotify = NULL;
 	}
 
-	if (notify->priv->status_icon != NULL &&
-	    gtk_status_icon_get_visible (notify->priv->status_icon)) {
-		notify->priv->libnotify = notify_notification_new_with_status_icon (title, content,
-										    msgicon,
-										    notify->priv->status_icon);
-	} else {
-		notify->priv->libnotify = notify_notification_new (title, content, msgicon, NULL);
-	}
+	notify->priv->libnotify = notify_notification_new (title, content, msgicon);
 
 	if (timeout == GPM_NOTIFY_TIMEOUT_NEVER) {
 		notify_notification_set_timeout (notify->priv->libnotify, 0);
