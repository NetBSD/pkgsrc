$NetBSD: patch-glib_gthread.c,v 1.3 2026/09/22 04:06:12 ryoon Exp $

Fix build on NetBSD.

--- glib/gthread.c.orig	2026-09-09 13:40:59.000000000 +0000
+++ glib/gthread.c
@@ -1187,7 +1187,7 @@ g_get_num_processors (void)
         pcore_count > 0)
       return pcore_count;
   }
-#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
   {
     int ncores = MIN (sysconf (_SC_NPROCESSORS_ONLN), CPU_SETSIZE);
     cpu_set_t cpu_mask;
