$NetBSD: patch-lib_multithreading.c,v 1.1 2026/05/01 19:43:30 vins Exp $

Improve portability: Use of pthread_threadid_np(2) or gettid(2) is never a
good idea, especially when pthread_equal(3) suffices.

--- lib/multithreading.c.orig	2025-11-14 13:33:44.250912762 +0000
+++ lib/multithreading.c
@@ -60,16 +60,12 @@
 
 nfs_tid_t nfs_mt_get_tid(void)
 {
-#ifdef HAVE_PTHREAD_THREADID_NP
-        nfs_tid_t tid;
-        pthread_threadid_np(NULL, &tid);
-        return tid;
-#elif defined(SYS_gettid)
-        pid_t tid = syscall(SYS_gettid);
-        return tid;
-#else
-#error "SYS_gettid unavailable on this system"
-#endif
+        return pthread_self();
+}
+
+int nfs_mt_equal(nfs_tid_t t1, nfs_tid_t t2)
+{
+        return pthread_equal(t1, t2);
 }
 
 static void *nfs_mt_service_thread(void *arg)
@@ -231,6 +227,10 @@ nfs_tid_t nfs_mt_get_tid(void)
 {
     return GetCurrentThreadId();
 }
+int nfs_mt_equal(nfs_tid_t t1, nfs_tid_t t2)
+{
+    return t1 == t2;
+}
 static void* nfs_mt_service_thread(void* arg)
 {
     struct nfs_context* nfs = (struct nfs_context*)arg;
