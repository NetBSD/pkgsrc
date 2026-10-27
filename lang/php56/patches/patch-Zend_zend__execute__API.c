$NetBSD: patch-Zend_zend__execute__API.c,v 1.1 2026/10/27 15:30:48 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend_execute_API.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_execute_API.c
@@ -330,6 +330,23 @@ void shutdown_executor(TSRMLS_D) /* {{{ 
 
 	zend_shutdown_fpu(TSRMLS_C);
 
+	/* A bailout may have skipped the resets above. zend_error() may use these
+	 * before the next init_executor(), e.g. for INI warnings or upload
+	 * progress during request startup (CVE-2026-109619). */
+	EG(user_error_handler) = NULL;
+	EG(user_exception_handler) = NULL;
+	EG(error_handling) = EH_NORMAL;
+	EG(exception_class) = NULL;
+	EG(exception) = NULL;
+	EG(prev_exception) = NULL;
+	EG(current_execute_data) = NULL;
+	EG(active_symbol_table) = NULL;
+	EG(active_op_array) = NULL;
+	EG(opline_ptr) = NULL;
+	EG(in_execution) = 0;
+	EG(in_autoload) = NULL;
+	EG(autoload_func) = NULL;
+
 	EG(active) = 0;
 }
 /* }}} */
@@ -639,6 +656,10 @@ int zend_call_function(zend_fcall_info *
 		return FAILURE; /* executor is already inactive */
 	}
 
+	if (ZEND_OOM_PENDING()) {
+		zend_handle_delayed_oom(TSRMLS_C);
+	}
+
 	if (EG(exception)) {
 		return FAILURE; /* we would result in an instable executor otherwise */
 	}
