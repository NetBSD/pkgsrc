$NetBSD: patch-lib_Support_BLAKE3-blake3__impl.h,v 1.1 2023/03/05 17:26:09 he Exp $

Pull patch over from rust:
Do not try to use neon on big-endian aarch64, as we have
an #error waiting there.

--- lib/Support/BLAKE3/blake3_impl.h.orig	2023-01-12 07:12:30.000000000 +0000
+++ lib/Support/BLAKE3/blake3_impl.h
@@ -64,7 +64,11 @@ enum blake3_flags {
 #if !defined(BLAKE3_USE_NEON) 
   // If BLAKE3_USE_NEON not manually set, autodetect based on AArch64ness
   #if defined(IS_AARCH64)
-    #define BLAKE3_USE_NEON 1
+    #if defined(__ARM_BIG_ENDIAN)
+      #define BLAKE3_USE_NEON 0
+    #else
+      #define BLAKE3_USE_NEON 1
+    #endif
   #else
     #define BLAKE3_USE_NEON 0
   #endif
