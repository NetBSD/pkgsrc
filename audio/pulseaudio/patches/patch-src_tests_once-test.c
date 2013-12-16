$NetBSD: patch-src_tests_once-test.c,v 1.1 2013/12/16 19:00:03 asau Exp $

--- src/tests/once-test.c.orig	2012-07-03 12:47:50.000000000 +0000
+++ src/tests/once-test.c	2013-09-26 00:26:09.760505519 +0000
@@ -25,6 +25,11 @@
 #include <pthread.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#endif
+
 #include <pulsecore/thread.h>
 #include <pulsecore/once.h>
 #include <pulsecore/log.h>
@@ -54,7 +59,11 @@
 
 #ifdef HAVE_PTHREAD_SETAFFINITY_NP
     static pa_atomic_t i_cpu = PA_ATOMIC_INIT(0);
+#if defined(__FreeBSD__)
+    cpuset_t mask;
+#else
     cpu_set_t mask;
+#endif
 
     CPU_ZERO(&mask);
     CPU_SET((size_t) (pa_atomic_inc(&i_cpu) % n_cpu), &mask);
