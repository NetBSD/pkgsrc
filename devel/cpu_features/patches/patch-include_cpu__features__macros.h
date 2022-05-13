$NetBSD: patch-include_cpu__features__macros.h,v 1.2 2022/05/13 10:39:35 tnn Exp $

NetBSD support.

--- include/cpu_features_macros.h.orig	2022-03-08 10:31:24.000000000 +0000
+++ include/cpu_features_macros.h
@@ -71,6 +71,10 @@
 #define CPU_FEATURES_OS_FREEBSD
 #endif
 
+#if defined(__NetBSD__)
+#define CPU_FEATURES_OS_NETBSD
+#endif
+
 #if defined(__ANDROID__)
 #define CPU_FEATURES_OS_ANDROID
 #endif
