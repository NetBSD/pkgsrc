$NetBSD: patch-gio_giomodule.c,v 1.4 2019/06/05 08:57:15 jperkin Exp $

Re-enable gdesktopappinfo on Darwin.
Disable inotify on SunOS.

--- gio/giomodule.c.orig	2019-05-03 13:43:28.000000000 +0000
+++ gio/giomodule.c
@@ -43,12 +43,9 @@
 #endif
 #include <glib/gstdio.h>
 
-#if defined(G_OS_UNIX) && !defined(HAVE_COCOA)
+#if defined(G_OS_UNIX)
 #include "gdesktopappinfo.h"
 #endif
-#ifdef HAVE_COCOA
-#include "gosxappinfo.h"
-#endif
 
 #ifdef HAVE_COCOA
 #include <AvailabilityMacros.h>
@@ -1084,7 +1081,7 @@ _g_io_modules_ensure_extension_points_re
     {
       registered_extensions = TRUE;
       
-#if defined(G_OS_UNIX) && !defined(HAVE_COCOA)
+#if defined(G_OS_UNIX)
 #if !GLIB_CHECK_VERSION (3, 0, 0)
       ep = g_io_extension_point_register (G_DESKTOP_APP_INFO_LOOKUP_EXTENSION_POINT_NAME);
       G_GNUC_BEGIN_IGNORE_DEPRECATIONS
@@ -1209,7 +1206,7 @@ _g_io_modules_ensure_loaded (void)
       /* Initialize types from built-in "modules" */
       g_type_ensure (g_null_settings_backend_get_type ());
       g_type_ensure (g_memory_settings_backend_get_type ());
-#if defined(HAVE_INOTIFY_INIT1)
+#if defined(HAVE_INOTIFY_INIT1) && !defined(__sun)
       g_type_ensure (g_inotify_file_monitor_get_type ());
 #endif
 #if defined(HAVE_KQUEUE)
@@ -1225,7 +1222,6 @@ _g_io_modules_ensure_loaded (void)
 #endif
 #ifdef HAVE_COCOA
       g_type_ensure (g_nextstep_settings_backend_get_type ());
-      g_type_ensure (g_osx_app_info_get_type ());
 #endif
 #ifdef G_OS_UNIX
       g_type_ensure (_g_unix_volume_monitor_get_type ());
