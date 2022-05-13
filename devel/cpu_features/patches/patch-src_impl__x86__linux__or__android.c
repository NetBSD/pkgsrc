$NetBSD: patch-src_impl__x86__linux__or__android.c,v 1.1 2022/05/13 10:39:35 tnn Exp $

Use /proc/cpuinfo on NetBSD/x86 for now.
Add placeholder SunOS implementation to fix the build.

--- src/impl_x86_linux_or_android.c.orig	2022-03-08 10:31:24.000000000 +0000
+++ src/impl_x86_linux_or_android.c
@@ -15,7 +15,14 @@
 #include "cpu_features_macros.h"
 
 #ifdef CPU_FEATURES_ARCH_X86
-#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID)
+#if defined(__sun)
+#include "impl_x86__base_implementation.inl"
+static void OverrideOsPreserves(OsPreserves* os_preserves) {
+}
+static void DetectFeaturesFromOs(X86Info* info, X86Features* features) {
+}
+#endif
+#if defined(CPU_FEATURES_OS_LINUX) || defined(CPU_FEATURES_OS_ANDROID) || defined(CPU_FEATURES_OS_NETBSD)
 
 #include "impl_x86__base_implementation.inl"
 
