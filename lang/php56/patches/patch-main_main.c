$NetBSD: patch-main_main.c,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- main/main.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ main/main.c
@@ -628,6 +628,7 @@ PHP_INI_BEGIN()
 	PHP_INI_ENTRY("disable_functions",			"",			PHP_INI_SYSTEM,		NULL)
 	PHP_INI_ENTRY("disable_classes",			"",			PHP_INI_SYSTEM,		NULL)
 	PHP_INI_ENTRY("max_file_uploads",			"20",			PHP_INI_SYSTEM|PHP_INI_PERDIR,		NULL)
+	PHP_INI_ENTRY("max_multipart_body_parts",	"-1",			PHP_INI_SYSTEM|PHP_INI_PERDIR,		NULL)
 
 	STD_PHP_INI_BOOLEAN("allow_url_fopen",		"1",		PHP_INI_SYSTEM,		OnUpdateBool,		allow_url_fopen,		php_core_globals,		core_globals)
 	STD_PHP_INI_BOOLEAN("allow_url_include",	"0",		PHP_INI_SYSTEM,		OnUpdateBool,		allow_url_include,		php_core_globals,		core_globals)
@@ -782,6 +783,13 @@ PHPAPI void php_verror(const char *docre
 	char *message;
 	int is_function = 0;
 
+	/* Do not pile up diagnostics while a memory limit error is pending, see
+	 * zend_handle_delayed_oom(). Fatal errors are still raised, as callers
+	 * may not expect them to return. */
+	if (ZEND_HAS_OOM() && !(type & (E_ERROR | E_CORE_ERROR | E_COMPILE_ERROR | E_USER_ERROR | E_RECOVERABLE_ERROR | E_PARSE))) {
+		return;
+	}
+
 	/* get error text into buffer and escape for html if necessary */
 	buffer_len = vspprintf(&buffer, 0, format, args);
 
@@ -1632,6 +1640,8 @@ int php_request_startup(TSRMLS_D)
 	signal(SIGCHLD, sigchld_handler);
 #endif
 
+	EG(delayed_oom) = ZEND_OOM_STATE_NONE;
+
 	zend_try {
 		PG(in_error_log) = 0;
 		PG(during_request_startup) = 1;
@@ -1645,6 +1655,7 @@ int php_request_startup(TSRMLS_D)
 		PG(in_user_include) = 0;
 
 		zend_activate(TSRMLS_C);
+		php_basic_early_rinit(TSRMLS_C);
 		sapi_activate(TSRMLS_C);
 
 #ifdef ZEND_SIGNALS
@@ -1822,6 +1833,11 @@ void php_request_shutdown(void *dummy)
 
 	report_memleaks = PG(report_memleaks);
 
+	/* A memory limit error that was already reported does not prevent the
+	 * shutdown functions and destructors from running, see
+	 * zend_handle_delayed_oom() */
+	EG(delayed_oom) = ZEND_OOM_STATE_NONE;
+
 	/* EG(opline_ptr) points into nirvana and therefore cannot be safely accessed
 	 * inside zend_executor callback functions.
 	 */
@@ -1880,6 +1896,8 @@ void php_request_shutdown(void *dummy)
 		for (i=0; i<NUM_TRACK_VARS; i++) {
 			if (PG(http_globals)[i]) {
 				zval_ptr_dtor(&PG(http_globals)[i]);
+				/* May be accessed before php_request_startup() */
+				PG(http_globals)[i] = NULL;
 			}
 		}
 	} zend_end_try();
@@ -1920,6 +1938,7 @@ void php_request_shutdown(void *dummy)
 	zend_try {
 		shutdown_memory_manager(CG(unclean_shutdown) || !report_memleaks, 0 TSRMLS_CC);
 	} zend_end_try();
+	EG(delayed_oom) = ZEND_OOM_STATE_NONE;
 	zend_interned_strings_restore(TSRMLS_C);
 
 	/* 12. Reset max_execution_time */
@@ -1937,6 +1956,9 @@ void php_request_shutdown(void *dummy)
 #ifdef HAVE_DTRACE
 	DTRACE_REQUEST_SHUTDOWN(SAFE_FILENAME(SG(request_info).path_translated), SAFE_FILENAME(SG(request_info).request_uri), (char *)SAFE_FILENAME(SG(request_info).request_method));
 #endif /* HAVE_DTRACE */
+
+	/* May be accessed before php_request_startup() */
+	PG(modules_activated) = 0;
 }
 /* }}} */
 
