$NetBSD: patch-glib_tests_thread.c,v 1.1 2024/04/09 16:57:18 wiz Exp $

Fix build on NetBSD.

--- glib/tests/thread.c.orig	2024-04-09 15:41:08.886542793 +0000
+++ glib/tests/thread.c
@@ -212,7 +212,7 @@ test_thread6 (void)
   g_thread_join (thread);
 }
 
-#if defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#if defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
 static gpointer
 thread7_func (gpointer data)
 {
@@ -243,7 +243,7 @@ thread7_func (gpointer data)
 static void
 test_thread7 (void)
 {
-#if defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#if defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
   GThread *thread = g_thread_new ("mask", thread7_func, NULL);
   gpointer result = g_thread_join (thread);
 
