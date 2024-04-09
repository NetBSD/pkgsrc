$NetBSD: patch-glib_gthread.c,v 1.1 2024/04/09 16:57:18 wiz Exp $

Fix build on NetBSD.

--- glib/gthread.c.orig	2024-04-09 16:24:39.087896412 +0000
+++ glib/gthread.c
@@ -1090,7 +1090,7 @@ g_get_num_processors (void)
 
   if (count > 0)
     return count;
-#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
   {
     int idx;
     int ncores = MIN (sysconf (_SC_NPROCESSORS_ONLN), CPU_SETSIZE);
