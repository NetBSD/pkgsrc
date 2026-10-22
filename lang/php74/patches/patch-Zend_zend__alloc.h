$NetBSD: patch-Zend_zend__alloc.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_alloc.h.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_alloc.h
@@ -402,6 +402,8 @@ static void apc_init_heap(void)
 size_t zend_mm_globals_size(void);
 #endif
 
+ZEND_API ZEND_COLD ZEND_NORETURN void zend_mm_safe_error_ex(const char *format, ...);
+
 END_EXTERN_C()
 
 #endif
