$NetBSD: patch-gio_gfile.c,v 1.1 2013/12/25 11:04:28 tron Exp $

Fix build with SunStudio compiler: void function cannot return value

--- gio/gfile.c.orig	2013-11-12 05:30:27.000000000 +0000
+++ gio/gfile.c	2013-12-25 09:58:51.000000000 +0000
@@ -7627,9 +7627,9 @@
   g_return_if_fail (G_IS_FILE (file));
   g_return_if_fail (cancellable == NULL || G_IS_CANCELLABLE (cancellable));
 
-  return G_FILE_GET_IFACE (file)->measure_disk_usage_async (file, flags, io_priority, cancellable,
-                                                            progress_callback, progress_data,
-                                                            callback, user_data);
+  G_FILE_GET_IFACE (file)->measure_disk_usage_async (file, flags, io_priority, cancellable,
+                                                     progress_callback, progress_data,
+                                                     callback, user_data);
 }
 
 /**
