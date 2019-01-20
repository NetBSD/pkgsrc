$NetBSD: patch-src_gallium_auxiliary_util_u__helpers.c,v 1.2 2019/01/20 09:50:28 tnn Exp $

handle NetBSD-style pthread_setaffinity_np(3)

--- src/gallium/auxiliary/util/u_helpers.c.orig	2018-12-11 21:13:57.000000000 +0000
+++ src/gallium/auxiliary/util/u_helpers.c
@@ -129,6 +129,19 @@ static once_flag thread_pinning_once_fla
 static void
 util_set_full_cpu_affinity(void)
 {
+#if defined(__NetBSD__)
+   cpuset_t *cpuset;
+
+   cpuset = cpuset_create();
+   if (cpuset != NULL) {
+      cpuset_zero(cpuset);
+      for (unsigned i = 0; i < cpuset_size(cpuset); i++)
+         cpuset_set(i, cpuset);
+
+      pthread_setaffinity_np(pthread_self(), cpuset_size(cpuset), cpuset);
+      cpuset_destroy(cpuset);
+   }
+#else
    cpu_set_t cpuset;
 
    CPU_ZERO(&cpuset);
@@ -136,6 +149,7 @@ util_set_full_cpu_affinity(void)
       CPU_SET(i, &cpuset);
 
    pthread_setaffinity_np(pthread_self(), sizeof(cpuset), &cpuset);
+#endif
 }
 
 static void
