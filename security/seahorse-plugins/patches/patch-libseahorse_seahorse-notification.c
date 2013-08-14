$NetBSD: patch-libseahorse_seahorse-notification.c,v 1.1 2013/08/14 08:30:06 obache Exp $

* fix build with libnotify-0.7
  https://git.gnome.org/browse/seahorse-plugins/commit/?id=fb74a75aa237c97c90dc1df2cfe36656a320e93e&ignorews=1

--- libseahorse/seahorse-notification.c.orig	2010-02-13 14:36:31.000000000 +0000
+++ libseahorse/seahorse-notification.c
@@ -34,6 +34,11 @@
 
 #ifdef HAVE_LIBNOTIFY
 #include <libnotify/notify.h>
+
+#ifndef NOTIFY_CHECK_VERSION
+#define NOTIFY_CHECK_VERSION(x,y,z) 0
+#endif
+
 #endif
 
 /* -----------------------------------------------------------------------------
@@ -213,7 +218,12 @@ setup_libnotify_notification (SeahorseNo
     heading = format_key_text (snotif->heading);
     message = format_key_text (snotif->message);
     
+/* libnotify 0.7.0 and later has no support for attaching to widgets */
+#if NOTIFY_CHECK_VERSION(0,7,0)
+    notif = notify_notification_new (heading, message, snotif->icon);
+#else
     notif = notify_notification_new (heading, message, snotif->icon, attachto);
+#endif
     
     g_free (heading);
     g_free (message);
