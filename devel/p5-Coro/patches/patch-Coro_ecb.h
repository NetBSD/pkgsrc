$NetBSD: patch-Coro_ecb.h,v 1.2 2015/01/29 00:48:51 mef Exp $

Use __builtin_unreachable on Clang instead of the broken C11 hack.

--- Coro/ecb.h.orig	2014-11-10 12:35:13.000000000 +0000
+++ Coro/ecb.h
@@ -523,7 +523,7 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined(__clang__)
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
