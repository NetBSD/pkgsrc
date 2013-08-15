$NetBSD: patch-src_manager.c,v 1.1 2013/08/15 05:45:54 obache Exp $

* for libnotify-0.7 API change

--- src/manager.c.orig	2009-02-15 20:55:39.000000000 +0000
+++ src/manager.c
@@ -3714,9 +3714,9 @@ gvm_statfs_check_space (const char *udi,
 			
 			icon = libhal_device_get_property_string (hal_ctx, udi, "info.icon_name", NULL);
 			if (icon != NULL)
-				n = notify_notification_new (_("Low Disk Space"), msg, icon, NULL);
+				n = notify_notification_new (_("Low Disk Space"), msg, icon);
 			else
-				n = notify_notification_new (_("Low Disk Space"), msg, "drive-harddisk", NULL);
+				n = notify_notification_new (_("Low Disk Space"), msg, "drive-harddisk");
 			
 			notify_notification_set_urgency (n, NOTIFY_URGENCY_CRITICAL);
 			notify_notification_show (n, NULL);
