$NetBSD: patch-src_llvm-project_llvm_lib_Support_BLAKE3_blake3__impl.h,v 1.3 2023/10/25 05:50:43 pin Exp $

Do not try to use neon on big-endian aarch64, as we have
an #error waiting there.

--- src/llvm-project/llvm/lib/Support/BLAKE3/blake3_impl.h.orig	2022-09-02 08:17:54.000000000 +0000
+++ src/llvm-project/llvm/lib/Support/BLAKE3/blake3_impl.h
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
