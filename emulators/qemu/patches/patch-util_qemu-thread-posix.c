$NetBSD: patch-util_qemu-thread-posix.c,v 1.2 2013/07/09 17:00:58 tsutsui Exp $

Fix a hangup problem under load of multiple disk xfers on NetBSD hosts:
 - fix a "fallback implementation of counting semaphores with mutex+condvar":
http://git.qemu.org/?p=qemu.git;a=commit;h=c166cb72f1676855816340666c3b618beef4b976
  - waiting threads are not restarted properly if more than one threads
    are waiting unblock signals in qemu_sem_timedwait()
  - possible missing pthread_cond_signal(3) calls when waiting threads
    are returned by ETIMEDOUT
 - fix an uninitialized variable
Discussed with and patch is provieded by soda@, with minor update
per comments on the qemu-devel mailing list:
http://lists.nongnu.org/archive/html/qemu-devel/2013-07/msg00030.html

--- util/qemu-thread-posix.c.orig	2013-06-26 21:47:30.000000000 +0000
+++ util/qemu-thread-posix.c
@@ -170,12 +170,11 @@ void qemu_sem_post(QemuSemaphore *sem)
 
 #if defined(__APPLE__) || defined(__NetBSD__)
     pthread_mutex_lock(&sem->lock);
-    if (sem->count == INT_MAX) {
+    if (sem->count == UINT_MAX) {
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
@@ -207,19 +206,21 @@ int qemu_sem_timedwait(QemuSemaphore *sem, int ms)
     struct timespec ts;
 
 #if defined(__APPLE__) || defined(__NetBSD__)
+    rc = 0;
     compute_abs_deadline(&ts, ms);
     pthread_mutex_lock(&sem->lock);
-    --sem->count;
-    while (sem->count < 0) {
+    while (sem->count == 0) {
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
@@ -249,16 +250,19 @@ int qemu_sem_timedwait(QemuSemaphore *sem, int ms)
 
 void qemu_sem_wait(QemuSemaphore *sem)
 {
+    int rc;
+
 #if defined(__APPLE__) || defined(__NetBSD__)
     pthread_mutex_lock(&sem->lock);
-    --sem->count;
-    while (sem->count < 0) {
-        pthread_cond_wait(&sem->cond, &sem->lock);
+    while (sem->count == 0) {
+        rc = pthread_cond_wait(&sem->cond, &sem->lock);
+        if (rc != 0) {
+            error_exit(rc, __func__);
+        }
     }
+    --sem->count;
     pthread_mutex_unlock(&sem->lock);
 #else
-    int rc;
-
     do {
         rc = sem_wait(&sem->sem);
     } while (rc == -1 && errno == EINTR);
