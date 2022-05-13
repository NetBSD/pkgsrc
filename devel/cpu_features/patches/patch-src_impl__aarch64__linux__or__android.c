$NetBSD: patch-src_impl__aarch64__linux__or__android.c,v 1.2 2022/05/13 18:19:07 tnn Exp $

Use /proc/cpuinfo on NetBSD/evbarm-aarch64 for now.

--- src/impl_aarch64_linux_or_android.c.orig	2022-03-08 10:31:24.000000000 +0000
+++ src/impl_aarch64_linux_or_android.c
@@ -15,7 +15,7 @@
 #include "cpu_features_macros.h"
 
 #ifdef CPU_FEATURES_ARCH_AARCH64
-#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID)
+#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID) || defined(CPU_FEATURES_OS_NETBSD) || defined(CPU_FEATURES_OS_MACOS)
 
 #include "cpuinfo_aarch64.h"
 
