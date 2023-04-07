$NetBSD: patch-atomic_unix_builtins64.c,v 1.3 2023/04/07 09:37:01 adam Exp $

Work around missing 64bit atomic builtins for non-x86 ILP32 platforms.

--- atomic/unix/builtins64.c.orig	2023-03-02 22:36:42.000000000 +0000
+++ atomic/unix/builtins64.c
@@ -16,7 +16,7 @@
 
 #include "apr_arch_atomic.h"
 
-#ifdef USE_ATOMICS_BUILTINS64
+#if defined (USE_ATOMICS_BUILTINS) && !defined (NEED_ATOMICS_GENERIC64)
 
 #if defined(__i386__) || defined(__x86_64__) \
     || defined(__s390__) || defined(__s390x__)
@@ -107,4 +107,4 @@ APR_DECLARE(apr_uint64_t) apr_atomic_xch
 #endif
 }
 
-#endif /* USE_ATOMICS_BUILTINS64 */
+#endif /* USE_ATOMICS_BUILTINS && !NEED_ATOMICS_GENERIC64 */
