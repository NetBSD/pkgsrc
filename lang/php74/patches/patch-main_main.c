$NetBSD: patch-main_main.c,v 1.1 2026/10/22 02:06:46 taca Exp $

Fix for CVE-2026-109618-109619.

--- main/main.c.orig	2022-10-31 10:36:05.000000000 +0000
+++ main/main.c
@@ -836,6 +836,7 @@ PHP_INI_BEGIN()
 	PHP_INI_ENTRY("disable_functions",			"",			PHP_INI_SYSTEM,		NULL)
 	PHP_INI_ENTRY("disable_classes",			"",			PHP_INI_SYSTEM,		NULL)
 	PHP_INI_ENTRY("max_file_uploads",			"20",			PHP_INI_SYSTEM|PHP_INI_PERDIR,		NULL)
+	PHP_INI_ENTRY("max_multipart_body_parts",	"-1",			PHP_INI_SYSTEM|PHP_INI_PERDIR,		NULL)
 
 	STD_PHP_INI_BOOLEAN("allow_url_fopen",		"1",		PHP_INI_SYSTEM,		OnUpdateBool,		allow_url_fopen,		php_core_globals,		core_globals)
 	STD_PHP_INI_BOOLEAN("allow_url_include",	"0",		PHP_INI_SYSTEM,		OnUpdateBool,		allow_url_include,		php_core_globals,		core_globals)
@@ -1960,6 +1961,8 @@ void php_request_shutdown(void *dummy)
 
 		for (i=0; i<NUM_TRACK_VARS; i++) {
 			zval_ptr_dtor(&PG(http_globals)[i]);
+			/* May be accessed before php_request_startup() */
+			ZVAL_UNDEF(&PG(http_globals)[i]);
 		}
 	} zend_end_try();
 
@@ -2012,6 +2015,9 @@ void php_request_shutdown(void *dummy)
 #ifdef HAVE_DTRACE
 	DTRACE_REQUEST_SHUTDOWN(SAFE_FILENAME(SG(request_info).path_translated), SAFE_FILENAME(SG(request_info).request_uri), (char *)SAFE_FILENAME(SG(request_info).request_method));
 #endif /* HAVE_DTRACE */
+
+	/* May be accessed before php_request_startup() */
+	PG(modules_activated) = 0;
 }
 /* }}} */
 
