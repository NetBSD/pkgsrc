$NetBSD: patch-src_impl__arm__linux__or__android.c,v 1.1 2022/05/13 18:19:07 tnn Exp $

--- src/impl_arm_linux_or_android.c.orig	2022-03-08 10:31:24.000000000 +0000
+++ src/impl_arm_linux_or_android.c
@@ -15,7 +15,7 @@
 #include "cpu_features_macros.h"
 
 #ifdef CPU_FEATURES_ARCH_ARM
-#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID)
+#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID) || defined(CPU_FEATURES_OS_NETBSD)
 
 #include "cpuinfo_arm.h"
 
