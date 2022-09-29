$NetBSD: patch-src_lib_caching_kshareddatacache_p.h,v 1.3 2022/09/29 00:36:31 markd Exp $

semaphoreTimedLock use must be wrapped by KSDC_TIMEOUTS_SUPPORTED

--- src/lib/caching/kshareddatacache_p.h.orig	2022-08-07 13:20:52.000000000 +0000
+++ src/lib/caching/kshareddatacache_p.h
@@ -394,9 +394,12 @@ static SharedLockId findBestSharedLock()
     {
         sem_t tempSemaphore;
         std::unique_ptr<KSDCLock> tempLock;
+#ifdef KSDC_TIMEOUTS_SUPPORTED
         if (timeoutsSupported) {
             tempLock = std::make_unique<semaphoreTimedLock>(tempSemaphore);
-        } else {
+        } else
+#endif
+	{
             tempLock = std::make_unique<semaphoreLock>(tempSemaphore);
         }
 
