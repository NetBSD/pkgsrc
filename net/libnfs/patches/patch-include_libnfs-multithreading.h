$NetBSD: patch-include_libnfs-multithreading.h,v 1.1 2026/05/01 19:43:30 vins Exp $

Improve portability: Use of pthread_threadid_np(2) or gettid(2) is never a
good idea, especially when pthread_equal(3) suffices.

--- include/libnfs-multithreading.h.orig	2025-11-14 13:32:34.996331119 +0000
+++ include/libnfs-multithreading.h
@@ -41,11 +41,7 @@ typedef dispatch_semaphore_t libnfs_sem_
 #include <semaphore.h>
 typedef sem_t libnfs_sem_t;
 #endif
-#ifdef HAVE_PTHREAD_THREADID_NP
-typedef uint64_t nfs_tid_t;
-#else
-typedef pid_t nfs_tid_t;
-#endif
+typedef libnfs_thread_t nfs_tid_t;
 #endif /* HAVE_PTHREAD */
 
 #ifdef WIN32
@@ -56,6 +52,8 @@ typedef DWORD nfs_tid_t;
 #endif
 
 nfs_tid_t nfs_mt_get_tid(void);
+int nfs_mt_equal(nfs_tid_t t1, nfs_tid_t t2);
+
 int nfs_mt_mutex_init(libnfs_mutex_t *mutex);
 int nfs_mt_mutex_destroy(libnfs_mutex_t *mutex);
 int nfs_mt_mutex_lock(libnfs_mutex_t *mutex);
