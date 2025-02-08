$NetBSD: patch-ext_intl_common_common__error.c,v 1.2 2025/02/08 02:57:59 taca Exp $

* Fix build with textproc/icu-68.1.

--- ext/intl/common/common_error.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/common/common_error.c
@@ -38,7 +38,7 @@ PHP_FUNCTION( intl_get_error_code )
 PHP_FUNCTION( intl_get_error_message )
 {
 	char* message = intl_error_get_message( NULL TSRMLS_CC );
-	RETURN_STRING( message, FALSE );
+	RETURN_STRING( message, false );
 }
 /* }}} */
 
