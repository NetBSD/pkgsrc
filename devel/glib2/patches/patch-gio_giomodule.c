$NetBSD: patch-gio_giomodule.c,v 1.5 2019/06/06 11:05:12 adam Exp $

Disable inotify on SunOS.

--- gio/giomodule.c.orig	2019-05-03 13:43:28.000000000 +0000
+++ gio/giomodule.c
@@ -1209,7 +1206,7 @@ _g_io_modules_ensure_loaded (void)
       /* Initialize types from built-in "modules" */
       g_type_ensure (g_null_settings_backend_get_type ());
       g_type_ensure (g_memory_settings_backend_get_type ());
-#if defined(HAVE_INOTIFY_INIT1)
+#if defined(HAVE_INOTIFY_INIT1) && !defined(__sun)
       g_type_ensure (g_inotify_file_monitor_get_type ());
 #endif
 #if defined(HAVE_KQUEUE)
