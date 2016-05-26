$NetBSD: patch-src_lib_caching_kshareddatacache_p.h,v 1.1 2016/05/26 08:29:04 markd Exp $

semaphoreTimedLock use must be wrapped by KSDC_TIMEOUTS_SUPPORTED

--- src/lib/caching/kshareddatacache_p.h.orig	2016-01-02 16:27:51.000000000 +0000
+++ src/lib/caching/kshareddatacache_p.h
@@ -395,9 +395,12 @@ static SharedLockId findBestSharedLock()
     {
         sem_t tempSemaphore;
         QSharedPointer<KSDCLock> tempLock(0);
+#ifdef KSDC_TIMEOUTS_SUPPORTED
         if (timeoutsSupported) {
             tempLock = QSharedPointer<KSDCLock>(new semaphoreTimedLock(tempSemaphore));
-        } else {
+        } else
+#endif
+        {
             tempLock = QSharedPointer<KSDCLock>(new semaphoreLock(tempSemaphore));
         }
 
