$NetBSD: patch-src_util_u__thread.h,v 1.2 2019/01/20 09:50:28 tnn Exp $

handle NetBSD-style pthread_setaffinity_np(3)

--- src/util/u_thread.h.orig	2018-12-11 21:13:57.000000000 +0000
+++ src/util/u_thread.h
@@ -83,6 +83,17 @@ static inline void
 util_pin_thread_to_L3(thrd_t thread, unsigned L3_index, unsigned cores_per_L3)
 {
 #if defined(HAVE_PTHREAD_SETAFFINITY)
+#if defined(__NetBSD__)
+   cpuset_t *cpuset;
+   cpuset = cpuset_create();
+   if (cpuset == NULL)
+      return;
+   cpuset_zero(cpuset);
+   for (unsigned i = 0; i < cores_per_L3; i++)
+      cpuset_set(L3_index * cores_per_L3 + i, cpuset);
+   pthread_setaffinity_np(thread, cpuset_size(cpuset), cpuset);
+   cpuset_destroy(cpuset);
+#else
    cpu_set_t cpuset;
 
    CPU_ZERO(&cpuset);
@@ -90,6 +101,7 @@ util_pin_thread_to_L3(thrd_t thread, uns
       CPU_SET(L3_index * cores_per_L3 + i, &cpuset);
    pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
 #endif
+#endif
 }
 
 /**
@@ -103,6 +115,35 @@ static inline int
 util_get_L3_for_pinned_thread(thrd_t thread, unsigned cores_per_L3)
 {
 #if defined(HAVE_PTHREAD_SETAFFINITY)
+#if defined(__NetBSD__)
+   cpuset_t *cpuset;
+
+   cpuset = cpuset_create();
+   if (cpuset == NULL)
+      return -1;
+
+   if (pthread_getaffinity_np(thread, cpuset_size(cpuset), cpuset) == 0) {
+      int L3_index = -1;
+
+      for (unsigned i = 0; i < cpuset_size(cpuset); i++) {
+         if (cpuset_isset(i, cpuset)) {
+            int x = i / cores_per_L3;
+
+            if (L3_index != x) {
+               if (L3_index == -1)
+                  L3_index = x;
+               else {
+                  cpuset_destroy(cpuset);
+                  return -1; /* multiple L3s are set */
+               }
+            }
+         }
+      }
+      cpuset_destroy(cpuset);
+      return L3_index;
+   }
+   cpuset_destroy(cpuset);
+#else
    cpu_set_t cpuset;
 
    if (pthread_getaffinity_np(thread, sizeof(cpuset), &cpuset) == 0) {
@@ -123,6 +164,7 @@ util_get_L3_for_pinned_thread(thrd_t thr
       return L3_index;
    }
 #endif
+#endif
    return -1;
 }
 
