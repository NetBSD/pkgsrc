$NetBSD: patch-client_gdaemonvfs.c,v 1.1 2026/05/10 17:38:14 vins Exp $

Don't crash when creating volume monitors if the VFS was never
initialized.

--- client/gdaemonvfs.c.orig	2026-03-13 10:15:46.000000000 +0000
+++ client/gdaemonvfs.c
@@ -1436,7 +1436,7 @@ g_daemon_vfs_deserialize_icon (GVfs     
 GDBusConnection *
 _g_daemon_vfs_get_async_bus (void)
 {
-  return the_vfs->async_bus;
+  return the_vfs ? the_vfs->async_bus : NULL;
 }
 
 static gboolean
