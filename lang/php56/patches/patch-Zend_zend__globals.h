$NetBSD: patch-Zend_zend__globals.h,v 1.1 2026/10/27 15:30:48 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend_globals.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_globals.h
@@ -265,6 +265,10 @@ struct _zend_executor_globals {
 #endif
 
 	void *reserved[ZEND_MAX_RESERVED_RESOURCES];
+
+	/* zend_oom_state, see zend_alloc.h. Kept last so that the offsets of the
+	 * fields above do not change. */
+	zend_uchar delayed_oom;
 };
 
 struct _zend_ini_scanner_globals {
