$NetBSD: patch-libraries_source_fcollada_src_FCollada_FUtils_FUCriticalSection.h,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- libraries/source/fcollada/src/FCollada/FUtils/FUCriticalSection.h.orig
+++ libraries/source/fcollada/src/FCollada/FUtils/FUCriticalSection.h
@@ -33,7 +33,7 @@ private:
 #elif defined(__APPLE__)
 	//Do something here.
 	MPCriticalRegionID criticalSection;
-#elif defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#elif defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #else
 #warning "FUCriticalSection: Critical section not implemented for other platforms."
 #endif
