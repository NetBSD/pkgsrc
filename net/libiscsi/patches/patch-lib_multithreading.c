$NetBSD: patch-lib_multithreading.c,v 1.1 2026/08/07 08:14:45 adam Exp $

Add thread id retrieval for FreeBSD/DragonFly, OpenBSD and NetBSD.
https://github.com/sahlberg/libiscsi/pull/466

--- lib/multithreading.c.orig	2025-07-15 09:27:12.000000000 +0000
+++ lib/multithreading.c
@@ -144,6 +144,12 @@ int iscsi_mt_sem_wait(libiscsi_sem_t* se
 #include <signal.h>
 #include <unistd.h>
 #include <sys/syscall.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <pthread_np.h>
+#endif
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
 
 iscsi_tid_t iscsi_mt_get_tid(void)
 {
@@ -151,6 +157,15 @@ iscsi_tid_t iscsi_mt_get_tid(void)
         iscsi_tid_t tid;
         pthread_threadid_np(NULL, &tid);
         return tid;
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+        int tid = pthread_getthreadid_np();
+        return tid;
+#elif defined(__OpenBSD__)
+        pid_t tid = getthrid();
+        return tid;
+#elif defined(__NetBSD__)
+        lwpid_t tid = _lwp_self();
+        return tid;
 #elif defined(SYS_gettid)
         pid_t tid = syscall(SYS_gettid);
         return tid;
