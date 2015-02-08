$NetBSD: patch-libeio_ecb.h,v 1.2 2015/02/08 02:49:50 mef Exp $

Use __builtin_unreachable on Clang instead of the broken C11 hack.

--- libeio/ecb.h.orig	2014-11-09 21:03:05.000000000 +0000
+++ libeio/ecb.h
@@ -468,7 +468,7 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined(__clang__)
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
