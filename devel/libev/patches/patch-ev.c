$NetBSD: patch-ev.c,v 1.1 2014/11/10 18:09:10 joerg Exp $

--- ev.c.orig	2014-11-09 20:47:55.000000000 +0000
+++ ev.c
@@ -963,7 +963,7 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined(__clang__)
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
