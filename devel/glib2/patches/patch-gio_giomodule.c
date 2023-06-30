$NetBSD: patch-gio_giomodule.c,v 1.8 2023/06/30 13:08:37 riastradh Exp $

Make Cocoa notification backend conditional.
Disable inotify on SunOS.

--- gio/giomodule.c.orig	2023-05-23 10:55:59.000000000 +0000
+++ gio/giomodule.c
@@ -1105,7 +1105,7 @@ extern GType g_proxy_resolver_portal_get
 extern GType g_network_monitor_portal_get_type (void);
 #endif
 
-#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
+#if defined(HAVE_COCOA) && MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
 extern GType g_cocoa_notification_backend_get_type (void);
 #endif
 
@@ -1346,7 +1346,7 @@ _g_io_modules_ensure_loaded (void)
       g_type_ensure (g_memory_settings_backend_get_type ());
       g_type_ensure (g_keyfile_settings_backend_get_type ());
       g_type_ensure (g_power_profile_monitor_dbus_get_type ());
-#if defined(HAVE_INOTIFY_INIT1)
+#if defined(HAVE_INOTIFY_INIT1) && !defined(__sun)
       g_type_ensure (g_inotify_file_monitor_get_type ());
 #endif
 #if defined(HAVE_KQUEUE)
@@ -1373,7 +1373,7 @@ _g_io_modules_ensure_loaded (void)
       g_type_ensure (g_power_profile_monitor_portal_get_type ());
       g_type_ensure (g_proxy_resolver_portal_get_type ());
 #endif
-#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
+#if defined(HAVE_COCOA) && MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
       g_type_ensure (g_cocoa_notification_backend_get_type ());
 #endif
 #ifdef G_OS_WIN32
