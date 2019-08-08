$NetBSD: patch-source_platform.h,v 1.1 2019/08/08 13:40:30 nia Exp $

This test is done too early for ARM and leads to misconfiguration.

--- source/platform.h.orig	2014-07-28 15:19:20.000000000 +0000
+++ source/platform.h
@@ -203,13 +203,6 @@
 #endif
 
 #if !defined (OS_DETECTED)
-#if defined (TARGET_CPU_ARM)
-#define OS_DETECTED
-#define TARGET_OS_NDSFIRMWARE
-#endif
-#endif
-
-#if !defined (OS_DETECTED)
 #if defined (MSDOS) || defined (__DOS__) || defined (__DJGPP__)
 #define OS_DETECTED
 #define TARGET_OS_DOS
@@ -258,6 +251,13 @@
 #endif
 #endif
 
+#if !defined (OS_DETECTED)
+#if defined (TARGET_CPU_ARM)
+#define OS_DETECTED
+#define TARGET_OS_NDSFIRMWARE
+#endif
+#endif
+
 //#if !defined (PROCESSOR_DETECTED)
 //#error "Could not detect target CPU."
 //#endif
