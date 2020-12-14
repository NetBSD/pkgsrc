$NetBSD: patch-include_cpu__features__macros.h,v 1.1 2020/12/14 15:07:49 tnn Exp $

NetBSD support.

--- include/cpu_features_macros.h.orig	2020-10-15 09:09:51.000000000 +0000
+++ include/cpu_features_macros.h
@@ -71,6 +71,10 @@
 #define CPU_FEATURES_OS_LINUX_OR_ANDROID
 #endif
 
+#if defined(__NetBSD__)
+#define CPU_FEATURES_OS_NETBSD
+#endif
+
 #if defined(__ANDROID__)
 #define CPU_FEATURES_OS_ANDROID
 #endif
