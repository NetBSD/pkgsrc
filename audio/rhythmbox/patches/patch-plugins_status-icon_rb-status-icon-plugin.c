$NetBSD: patch-plugins_status-icon_rb-status-icon-plugin.c,v 1.1 2013/08/15 08:04:29 obache Exp $

* for libnotify-0.7 API change

--- plugins/status-icon/rb-status-icon-plugin.c.orig	2010-03-25 00:10:13.000000000 +0000
+++ plugins/status-icon/rb-status-icon-plugin.c
@@ -394,7 +394,7 @@ do_notify (RBStatusIconPlugin *plugin,
 		icon_name = NULL;
 
 	if (plugin->priv->notification == NULL) {
-		plugin->priv->notification = notify_notification_new (primary, secondary, icon_name, NULL);
+		plugin->priv->notification = notify_notification_new (primary, secondary, icon_name);
 
 		g_signal_connect_object (plugin->priv->notification,
 					 "closed",
