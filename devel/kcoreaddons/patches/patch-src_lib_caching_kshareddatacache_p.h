$NetBSD: patch-src_lib_caching_kshareddatacache_p.h,v 1.2 2018/01/17 20:00:20 markd Exp $

semaphoreTimedLock use must be wrapped by KSDC_TIMEOUTS_SUPPORTED

--- src/lib/caching/kshareddatacache_p.h.orig	2017-12-02 20:03:05.000000000 +0000
+++ src/lib/caching/kshareddatacache_p.h
@@ -401,9 +401,12 @@ static SharedLockId findBestSharedLock()
     {
         sem_t tempSemaphore;
         QSharedPointer<KSDCLock> tempLock;
+#ifdef KSDC_TIMEOUTS_SUPPORTED
         if (timeoutsSupported) {
             tempLock = QSharedPointer<KSDCLock>(new semaphoreTimedLock(tempSemaphore));
-        } else {
+        } else
+#endif
+        {
             tempLock = QSharedPointer<KSDCLock>(new semaphoreLock(tempSemaphore));
         }
 
