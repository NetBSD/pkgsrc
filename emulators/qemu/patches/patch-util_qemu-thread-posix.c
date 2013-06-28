$NetBSD: patch-util_qemu-thread-posix.c,v 1.1 2013/06/28 19:30:28 tsutsui Exp $

Fix a hangup problem under load of multiple disk xfers on NetBSD hosts:
 - fix a "fallback implementation of counting semaphores with mutex+condvar":
http://git.qemu.org/?p=qemu.git;a=commit;h=c166cb72f1676855816340666c3b618beef4b976
  - waiting threads are not restarted properly if more than one threads
    are waiting unblock signals in qemu_sem_timedwait()
  - possible missing pthread_cond_signal(3) calls when waiting threads
    are returned by ETIMEDOUT
 - fix an uninitialized variable
Discussed with and patch is provieded by soda@.

--- util/qemu-thread-posix.c.orig	2013-05-24 13:37:58.000000000 +0000
+++ util/qemu-thread-posix.c
@@ -172,10 +172,9 @@ void qemu_sem_post(QemuSemaphore *sem)
     pthread_mutex_lock(&sem->lock);
     if (sem->count == INT_MAX) {
         rc = EINVAL;
-    } else if (sem->count++ < 0) {
-        rc = pthread_cond_signal(&sem->cond);
     } else {
-        rc = 0;
+        sem->count++;
+        rc = pthread_cond_signal(&sem->cond);
     }
     pthread_mutex_unlock(&sem->lock);
     if (rc != 0) {
@@ -207,19 +206,21 @@ int qemu_sem_timedwait(QemuSemaphore *se
     struct timespec ts;
 
 #if defined(__APPLE__) || defined(__NetBSD__)
+    rc = 0;
     compute_abs_deadline(&ts, ms);
     pthread_mutex_lock(&sem->lock);
-    --sem->count;
-    while (sem->count < 0) {
+    while (sem->count <= 0) {
         rc = pthread_cond_timedwait(&sem->cond, &sem->lock, &ts);
         if (rc == ETIMEDOUT) {
-            ++sem->count;
             break;
         }
         if (rc != 0) {
             error_exit(rc, __func__);
         }
     }
+    if (rc != ETIMEDOUT) {
+        --sem->count;
+    }
     pthread_mutex_unlock(&sem->lock);
     return (rc == ETIMEDOUT ? -1 : 0);
 #else
@@ -251,10 +252,10 @@ void qemu_sem_wait(QemuSemaphore *sem)
 {
 #if defined(__APPLE__) || defined(__NetBSD__)
     pthread_mutex_lock(&sem->lock);
-    --sem->count;
-    while (sem->count < 0) {
+    while (sem->count <= 0) {
         pthread_cond_wait(&sem->cond, &sem->lock);
     }
+    --sem->count;
     pthread_mutex_unlock(&sem->lock);
 #else
     int rc;
