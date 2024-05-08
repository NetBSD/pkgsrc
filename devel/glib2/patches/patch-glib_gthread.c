$NetBSD: patch-glib_gthread.c,v 1.2 2024/05/08 15:44:20 adam Exp $

Fix build on NetBSD.

--- glib/gthread.c.orig	2024-05-07 14:50:30.000000000 +0000
+++ glib/gthread.c
@@ -1090,7 +1090,7 @@ g_get_num_processors (void)
 
   if (count > 0)
     return count;
-#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
   {
     int ncores = MIN (sysconf (_SC_NPROCESSORS_ONLN), CPU_SETSIZE);
     cpu_set_t cpu_mask;
