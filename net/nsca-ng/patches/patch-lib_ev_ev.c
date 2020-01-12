$NetBSD: patch-lib_ev_ev.c,v 1.1 2020/01/12 23:02:16 joerg Exp $

clang has __builtin_unreachable, but also fix _Noreturn use for C11
compiler.

--- lib/ev/ev.c.orig	2020-01-12 21:38:53.341023307 +0000
+++ lib/ev/ev.c
@@ -963,11 +963,11 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined(__clang__)
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
+  ecb_inline ecb_noreturn void ecb_unreachable (void);
   ecb_inline void ecb_unreachable (void) { }
 #endif
 
