$NetBSD: patch-src_util_u__thread.h,v 1.5 2022/03/13 15:50:05 tnn Exp $

Oracle Solaris has pthread_setname_np. illumos does not.
(actually, newer Illumos does have it, but never mind.)

Don't hard error when there's no pthread_setname_np.

handle NetBSD-style pthread_setaffinity_np(3)

--- src/util/u_thread.h.orig	2021-08-04 18:49:29.374474500 +0000
+++ src/util/u_thread.h
@@ -129,7 +129,7 @@ static inline thrd_t u_thread_create(int
 static inline void u_thread_setname( const char *name )
 {
 #if defined(HAVE_PTHREAD)
-#if DETECT_OS_LINUX || DETECT_OS_CYGWIN || DETECT_OS_SOLARIS
+#if DETECT_OS_LINUX || DETECT_OS_CYGWIN
    int ret = pthread_setname_np(pthread_self(), name);
    if (ret == ERANGE) {
       char buf[16];
@@ -169,8 +169,32 @@ util_set_thread_affinity(thrd_t thread,
                          unsigned num_mask_bits)
 {
 #if defined(HAVE_PTHREAD_SETAFFINITY)
-   cpu_set_t cpuset;
+# if defined(__NetBSD__)
+   cpu_set_t *cpuset;
+   cpuset = cpuset_create();
+   if (cpuset == NULL)
+      return;
+   if (old_mask) {
+      if (pthread_getaffinity_np(thread, cpuset_size(cpuset), cpuset) != 0)
+         return false;
 
+      memset(old_mask, 0, num_mask_bits / 8);
+      for (unsigned i = 0; i < num_mask_bits && i < CPU_SETSIZE; i++) {
+         if (cpuset_isset(i, cpuset))
+            old_mask[i / 32] |= 1u << (i % 32);
+      }
+   }
+
+   cpuset_zero(cpuset);
+   for (unsigned i = 0; i < num_mask_bits && i < CPU_SETSIZE; i++) {
+      if (mask[i / 32] & (1u << (i % 32)))
+         cpuset_set(i, cpuset);
+   }
+   int err = pthread_setaffinity_np(thread, cpuset_size(cpuset), cpuset);
+   cpuset_destroy(cpuset);
+   return err == 0;
+# else
+   cpu_set_t cpuset;
    if (old_mask) {
       if (pthread_getaffinity_np(thread, sizeof(cpuset), &cpuset) != 0)
          return false;
@@ -188,7 +212,7 @@ util_set_thread_affinity(thrd_t thread,
          CPU_SET(i, &cpuset);
    }
    return pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset) == 0;
-
+# endif
 #elif defined(_WIN32) && !defined(__CYGWIN__)
    DWORD_PTR m = mask[0];
 
@@ -242,7 +266,7 @@ util_set_current_thread_affinity(const u
 static inline int64_t
 util_thread_get_time_nano(thrd_t thread)
 {
-#if defined(HAVE_PTHREAD) && !defined(__APPLE__) && !defined(__HAIKU__)
+#if defined(HAVE_PTHREAD) && !defined(__APPLE__) && !defined(__HAIKU__) && !defined(__sun)
    struct timespec ts;
    clockid_t cid;
 
