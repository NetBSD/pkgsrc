$NetBSD: patch-gio_giomodule.c,v 1.1 2017/07/11 11:52:42 jperkin Exp $

Re-enable gdesktopappinfo on Darwin.

--- gio/giomodule.c.orig	2017-06-22 12:52:49.000000000 +0000
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
@@ -978,7 +975,7 @@ _g_io_modules_ensure_extension_points_re
     {
       registered_extensions = TRUE;
       
-#if defined(G_OS_UNIX) && !defined(HAVE_COCOA)
+#if defined(G_OS_UNIX)
 #if !GLIB_CHECK_VERSION (3, 0, 0)
       ep = g_io_extension_point_register (G_DESKTOP_APP_INFO_LOOKUP_EXTENSION_POINT_NAME);
       G_GNUC_BEGIN_IGNORE_DEPRECATIONS
@@ -1119,7 +1116,6 @@ _g_io_modules_ensure_loaded (void)
 #endif
 #ifdef HAVE_COCOA
       g_type_ensure (g_nextstep_settings_backend_get_type ());
-      g_type_ensure (g_osx_app_info_get_type ());
 #endif
 #ifdef G_OS_UNIX
       g_type_ensure (_g_unix_volume_monitor_get_type ());
