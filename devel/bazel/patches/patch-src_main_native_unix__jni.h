$NetBSD: patch-src_main_native_unix__jni.h,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/main/native/unix_jni.h.orig	2023-11-29 05:49:36.312797541 +0000
+++ src/main/native/unix_jni.h
@@ -25,7 +25,7 @@
 
 namespace blaze_jni {
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 // stat64 is deprecated on OS X/BSD.
 typedef struct stat portable_stat_struct;
 #define portable_stat ::stat
