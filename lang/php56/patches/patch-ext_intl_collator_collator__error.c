$NetBSD: patch-ext_intl_collator_collator__error.c,v 1.2 2025/02/08 02:57:59 taca Exp $

* Fix build with textproc/icu-68.1.

--- ext/intl/collator/collator_error.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/collator/collator_error.c
@@ -80,7 +80,7 @@ PHP_FUNCTION( collator_get_error_message
 
 	/* Return last error message. */
 	message = intl_error_get_message( COLLATOR_ERROR_P( co ) TSRMLS_CC );
-	RETURN_STRING( (char*)message, FALSE );
+	RETURN_STRING( (char*)message, false );
 }
 /* }}} */
 
