$NetBSD: patch-ecb.h,v 1.1 2014/12/18 10:51:59 joerg Exp $

--- ecb.h.orig	2014-12-15 12:08:33.000000000 +0000
+++ ecb.h
@@ -512,7 +512,7 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined(__clang__)
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
