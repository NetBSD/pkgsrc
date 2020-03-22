$NetBSD: patch-hotspot_src_cpu_x86_vm_jni__x86.h,v 1.1 2020/03/22 21:22:20 joerg Exp $

--- hotspot/src/cpu/x86/vm/jni_x86.h.orig	2020-03-22 17:50:27.459024653 +0000
+++ hotspot/src/cpu/x86/vm/jni_x86.h
@@ -28,7 +28,7 @@
 
 #if defined(SOLARIS) || defined(LINUX) || defined(_ALLBSD_SOURCE)
 
-#if defined(__GNUC__) && (__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2)
+#if defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2) || defined(__clang__))
   #define JNIEXPORT     __attribute__((visibility("default")))
   #define JNIIMPORT     __attribute__((visibility("default")))
 #else
