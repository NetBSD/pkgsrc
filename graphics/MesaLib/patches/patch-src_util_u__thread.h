$NetBSD: patch-src_util_u__thread.h,v 1.2 2019/10/19 10:29:58 nia Exp $

Don't hard error when there's no pthread_setname_np.

handle NetBSD-style pthread_setaffinity_np(3)

--- src/util/u_thread.h.orig	2019-10-09 16:52:00.000000000 +0000
+++ src/util/u_thread.h
@@ -78,7 +78,6 @@ static inline void u_thread_setname( con
 #elif DETECT_OS_APPLE
    pthread_setname_np(name);
 #else
-#error Not sure how to call pthread_setname_np
 #endif
 #endif
    (void)name;
@@ -98,6 +97,17 @@ static inline void
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
@@ -105,6 +115,7 @@ util_pin_thread_to_L3(thrd_t thread, uns
       CPU_SET(L3_index * cores_per_L3 + i, &cpuset);
    pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
 #endif
+#endif
 }
 
 /**
@@ -118,6 +129,35 @@ static inline int
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
@@ -138,6 +178,7 @@ util_get_L3_for_pinned_thread(thrd_t thr
       return L3_index;
    }
 #endif
+#endif
    return -1;
 }
 
