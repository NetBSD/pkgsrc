$NetBSD: patch-dbus_dbus-sysdeps-util-unix.c,v 1.1 2012/08/09 10:21:19 jperkin Exp $

HAVE_DECL_LOG_PERROR is always defined, we care more whether it is 0 or 1.

--- dbus/dbus-sysdeps-util-unix.c.orig	Thu Aug  9 10:07:27 2012
+++ dbus/dbus-sysdeps-util-unix.c	Thu Aug  9 10:07:33 2012
@@ -424,7 +424,7 @@
 void
 _dbus_init_system_log (void)
 {
-#ifdef HAVE_DECL_LOG_PERROR
+#if HAVE_DECL_LOG_PERROR
   openlog ("dbus", LOG_PID | LOG_PERROR, LOG_DAEMON);
 #else
   openlog ("dbus", LOG_PID, LOG_DAEMON);
