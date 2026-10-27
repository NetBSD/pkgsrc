$NetBSD: patch-ext_standard_basic__functions.h,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- ext/standard/basic_functions.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/standard/basic_functions.h
@@ -230,6 +230,13 @@ typedef struct _php_basic_globals {
 #endif
 
 	int umask;
+
+	/* var.c: while non-zero, php_var_unserialize() represents every object
+	 * as __PHP_Incomplete_Class without resolving its class, and
+	 * php_var_serialize() writes such objects back unchanged. Used by the
+	 * session upload progress handler, which runs before RINIT. Kept last so
+	 * that the offsets of the fields above do not change. */
+	unsigned incomplete_classes_only;
 } php_basic_globals;
 
 #ifdef ZTS
@@ -261,6 +268,7 @@ PHPAPI extern zend_bool register_user_sh
 PHPAPI extern zend_bool remove_user_shutdown_function(char *function_name, size_t function_len TSRMLS_DC);
 PHPAPI extern zend_bool append_user_shutdown_function(php_shutdown_function_entry shutdown_function_entry TSRMLS_DC);
 
+PHPAPI void php_basic_early_rinit(TSRMLS_D);
 PHPAPI void php_call_shutdown_functions(TSRMLS_D);
 PHPAPI void php_free_shutdown_functions(TSRMLS_D);
 
