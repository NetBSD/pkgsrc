$NetBSD: patch-gio_giomodule.c,v 1.6 2019/08/20 14:06:46 wiz Exp $

Disable inotify on SunOS.

--- gio/giomodule.c.orig	2019-07-24 10:52:04.000000000 +0000
+++ gio/giomodule.c
@@ -1210,7 +1210,7 @@ _g_io_modules_ensure_loaded (void)
       g_type_ensure (g_null_settings_backend_get_type ());
       g_type_ensure (g_memory_settings_backend_get_type ());
       g_type_ensure (g_keyfile_settings_backend_get_type ());
-#if defined(HAVE_INOTIFY_INIT1)
+#if defined(HAVE_INOTIFY_INIT1) && !defined(__sun)
       g_type_ensure (g_inotify_file_monitor_get_type ());
 #endif
 #if defined(HAVE_KQUEUE)
