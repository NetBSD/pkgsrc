$NetBSD: patch-glib_glib_gtimer.c,v 1.2 2015/10/15 09:47:56 wiz Exp $

--- glib/glib/gtimer.c.orig	2014-02-08 17:57:06.000000000 +0000
+++ glib/glib/gtimer.c
@@ -254,6 +254,8 @@ g_usleep (gulong microseconds)
 {
 #ifdef G_OS_WIN32
   Sleep (microseconds / 1000);
+#elif defined(_SCO_DS)
+  usleep(microseconds);
 #else
   struct timespec request, remaining;
   request.tv_sec = microseconds / G_USEC_PER_SEC;
