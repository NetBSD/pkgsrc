$NetBSD: patch-Zend_zend.c,v 1.1 2026/10/27 15:30:48 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend.c
@@ -577,6 +577,7 @@ static void executor_globals_ctor(zend_e
 #endif
 	EG(saved_fpu_cw_ptr) = NULL;
 	EG(active) = 0;
+	EG(delayed_oom) = ZEND_OOM_STATE_NONE;
 }
 /* }}} */
 
@@ -1339,6 +1340,9 @@ ZEND_API int zend_execute_scripts(int ty
 		if (EG(active_op_array)) {
 			EG(return_value_ptr_ptr) = retval ? retval : NULL;
 			zend_execute(EG(active_op_array) TSRMLS_CC);
+			if (ZEND_OOM_PENDING()) {
+				zend_handle_delayed_oom(TSRMLS_C);
+			}
 			zend_exception_restore(TSRMLS_C);
 			if (EG(exception)) {
 				if (EG(user_exception_handler)) {
