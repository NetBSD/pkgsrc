$NetBSD: patch-atomic_unix_builtins64.c,v 1.1 2020/02/20 06:25:28 rin Exp $

Work around missing 64bit atomic builtins for non-x86 ILP32 platforms.

--- atomic/unix/builtins64.c.orig	2020-02-19 16:06:32.153732769 +0900
+++ atomic/unix/builtins64.c	2020-02-19 16:08:48.239198201 +0900
@@ -16,7 +16,7 @@
 
 #include "apr_arch_atomic.h"
 
-#ifdef USE_ATOMICS_BUILTINS
+#if defined (USE_ATOMICS_BUILTINS) && !defined (NEED_ATOMICS_GENERIC64)
 
 APR_DECLARE(apr_uint64_t) apr_atomic_read64(volatile apr_uint64_t *mem)
 {
@@ -61,4 +61,4 @@ APR_DECLARE(apr_uint64_t) apr_atomic_xch
     return __sync_lock_test_and_set(mem, val);
 }
 
-#endif /* USE_ATOMICS_BUILTINS */
+#endif /* USE_ATOMICS_BUILTINS && !NEED_ATOMICS_GENERIC64 */
