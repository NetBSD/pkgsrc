$NetBSD: patch-atomic_unix_builtins64.c,v 1.2 2023/01/31 18:41:49 wiz Exp $

Work around missing 64bit atomic builtins for non-x86 ILP32 platforms.

--- atomic/unix/builtins64.c.orig	2022-06-27 21:55:09.000000000 +0000
+++ atomic/unix/builtins64.c
@@ -16,7 +16,7 @@
 
 #include "apr_arch_atomic.h"
 
-#ifdef USE_ATOMICS_BUILTINS64
+#if defined (USE_ATOMICS_BUILTINS) && !defined (NEED_ATOMICS_GENERIC64)
 
 #if defined(__arm__) || defined(__powerpc__) || defined(__powerpc64__)
 #define WEAK_MEMORY_ORDERING 1
@@ -106,4 +106,4 @@ APR_DECLARE(apr_uint64_t) apr_atomic_xch
 #endif
 }
 
-#endif /* USE_ATOMICS_BUILTINS64 */
+#endif /* USE_ATOMICS_BUILTINS && !NEED_ATOMICS_GENERIC64 */
