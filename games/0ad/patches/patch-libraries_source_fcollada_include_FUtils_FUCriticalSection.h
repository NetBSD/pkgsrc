$NetBSD: patch-libraries_source_fcollada_include_FUtils_FUCriticalSection.h,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- libraries/source/fcollada/include/FUtils/FUCriticalSection.h.orig	2021-08-25 14:44:15.000000000 +0000
+++ libraries/source/fcollada/include/FUtils/FUCriticalSection.h
@@ -33,7 +33,7 @@ private:
 #elif defined(__APPLE__)
 	//Do something here.
 	MPCriticalRegionID criticalSection;
-#elif defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#elif defined(LINUX) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #else
 #warning "FUCriticalSection: Critical section not implemented for other platforms."
 #endif
