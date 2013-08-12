$NetBSD: patch-plugins_a11y-keyboard_gsd-a11y-keyboard-manager.c,v 1.1 2013/08/12 09:10:09 obache Exp $

* Require libnotify 0.6.0
  https://git.gnome.org/browse/gnome-settings-daemon/commit/?id=e1ab570b0dce479ba235e5542ea07d1b5bafc4c9

--- plugins/a11y-keyboard/gsd-a11y-keyboard-manager.c.orig	2010-11-15 13:10:51.000000000 +0000
+++ plugins/a11y-keyboard/gsd-a11y-keyboard-manager.c
@@ -608,9 +608,7 @@ ax_slowkeys_warning_post_bubble (GsdA11y
         gsd_a11y_keyboard_manager_ensure_status_icon (manager);
         manager->priv->notification = notify_notification_new (title,
                                                                message,
-                                                               "preferences-desktop-accessibility",
-                                                               NULL);
-        notify_notification_attach_to_status_icon (manager->priv->notification, manager->priv->status_icon);
+                                                               "preferences-desktop-accessibility");
         notify_notification_set_timeout (manager->priv->notification, NOTIFICATION_TIMEOUT * 1000);
 
         notify_notification_add_action (manager->priv->notification,
@@ -747,9 +745,7 @@ ax_stickykeys_warning_post_bubble (GsdA1
         gsd_a11y_keyboard_manager_ensure_status_icon (manager);
         manager->priv->notification = notify_notification_new (title,
                                                                message,
-                                                               "preferences-desktop-accessibility",
-                                                               NULL);
-        notify_notification_attach_to_status_icon (manager->priv->notification, manager->priv->status_icon);
+                                                               "preferences-desktop-accessibility");
         notify_notification_set_timeout (manager->priv->notification, NOTIFICATION_TIMEOUT * 1000);
 
         notify_notification_add_action (manager->priv->notification,
