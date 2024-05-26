$NetBSD: patch-src_lib_caching_ksdclock.cpp,v 1.1 2024/05/26 11:26:13 markd Exp $

semaphoreTimedLock use must be wrapped by KSDC_TIMEOUTS_SUPPORTED

--- src/lib/caching/ksdclock.cpp.orig	2024-05-03 12:24:08.000000000 +0000
+++ src/lib/caching/ksdclock.cpp
@@ -56,9 +56,12 @@ SharedLockId findBestSharedLock()
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
 
