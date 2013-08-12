$NetBSD: patch-plugins_xrandr_gsd-xrandr-manager.c,v 1.1 2013/08/12 09:10:09 obache Exp $

* Require libnotify 0.6.0
  https://git.gnome.org/browse/gnome-settings-daemon/commit/?id=e1ab570b0dce479ba235e5542ea07d1b5bafc4c9

--- plugins/xrandr/gsd-xrandr-manager.c.orig	2010-11-15 13:11:00.000000000 +0000
+++ plugins/xrandr/gsd-xrandr-manager.c
@@ -1086,16 +1086,9 @@ error_message (GsdXrandrManager *mgr, co
 
         g_assert (error_to_display == NULL || secondary_text == NULL);
 
-        if (priv->status_icon)
-                notification = notify_notification_new_with_status_icon (primary_text,
-                                                                         error_to_display ? error_to_display->message : secondary_text,
-                                                                         GSD_XRANDR_ICON_NAME,
-                                                                         priv->status_icon);
-        else
-                notification = notify_notification_new (primary_text,
-                                                        error_to_display ? error_to_display->message : secondary_text,
-                                                        GSD_XRANDR_ICON_NAME,
-                                                        NULL);
+        notification = notify_notification_new (primary_text,
+                                                error_to_display ? error_to_display->message : secondary_text,
+                                                GSD_XRANDR_ICON_NAME);
 
         notify_notification_show (notification, NULL); /* NULL-GError */
 #else
