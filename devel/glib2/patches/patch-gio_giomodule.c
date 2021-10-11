$NetBSD: patch-gio_giomodule.c,v 1.7 2021/10/11 10:03:47 cirnatdan Exp $

Disable inotify on SunOS.

--- gio/giomodule.c.orig	2021-09-17 10:17:56.682960300 +0000
+++ gio/giomodule.c
@@ -1280,7 +1280,7 @@ _g_io_modules_ensure_loaded (void)
       g_type_ensure (g_memory_settings_backend_get_type ());
       g_type_ensure (g_keyfile_settings_backend_get_type ());
       g_type_ensure (g_power_profile_monitor_dbus_get_type ());
-#if defined(HAVE_INOTIFY_INIT1)
+#if defined(HAVE_INOTIFY_INIT1) && !defined(__sun)
       g_type_ensure (g_inotify_file_monitor_get_type ());
 #endif
 #if defined(HAVE_KQUEUE)
