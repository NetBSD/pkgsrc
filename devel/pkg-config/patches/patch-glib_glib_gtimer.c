$NetBSD: patch-glib_glib_gtimer.c,v 1.1 2014/07/18 19:50:47 ryoon Exp $

--- glib/glib/gtimer.c.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/gtimer.c
@@ -252,6 +252,8 @@ g_usleep (gulong microseconds)
 {
 #ifdef G_OS_WIN32
   Sleep (microseconds / 1000);
+#elif defined(_SCO_DS)
+  usleep(microseconds);
 #else
   struct timespec request, remaining;
   request.tv_sec = microseconds / G_USEC_PER_SEC;
