$NetBSD: patch-atomic_unix_builtins.c,v 1.1 2020/02/20 06:25:28 rin Exp $

Work around missing 64bit atomic builtins for non-x86 ILP32 platforms.

--- atomic/unix/builtins.c.orig	2020-02-19 16:07:42.205846916 +0900
+++ atomic/unix/builtins.c	2020-02-19 16:08:29.237974955 +0900
@@ -20,7 +20,11 @@
 
 APR_DECLARE(apr_status_t) apr_atomic_init(apr_pool_t *p)
 {
+#ifdef NEED_ATOMICS_GENERIC64
+    return apr__atomic_generic64_init(p);
+#else
     return APR_SUCCESS;
+#endif
 }
 
 APR_DECLARE(apr_uint32_t) apr_atomic_read32(volatile apr_uint32_t *mem)
