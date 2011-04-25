$NetBSD: patch-libnotify_notification.c,v 1.1 2011/04/25 08:55:28 adam Exp $

Fix building with GDK with Quartz (Mac OS X) backend.

--- libnotify/notification.c.orig	2011-04-25 08:35:15.000000000 +0000
+++ libnotify/notification.c
@@ -31,7 +31,9 @@
 # define HAVE_STATUS_ICON
 # include <gtk/gtkstatusicon.h>
 #endif
+#ifndef GDK_WINDOWING_QUARTZ
 #include <gdk/gdkx.h>
+#endif
 
 #define CHECK_DBUS_VERSION(major, minor) \
 	(DBUS_MAJOR_VER > (major) || \
