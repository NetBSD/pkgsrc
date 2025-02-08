$NetBSD: patch-ext_intl_normalizer_normalizer__normalize.c,v 1.2 2025/02/08 02:57:59 taca Exp $

* Fix build with textproc/icu-68.1.

--- ext/intl/normalizer/normalizer_normalize.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/normalizer/normalizer_normalize.c
@@ -159,7 +159,7 @@ PHP_FUNCTION( normalizer_normalize )
 	}
 
 	/* Return it. */
-	RETVAL_STRINGL( ret_buf, ret_len, FALSE );
+	RETVAL_STRINGL( ret_buf, ret_len, false );
 }
 /* }}} */
 
@@ -179,7 +179,7 @@ PHP_FUNCTION( normalizer_is_normalized )
 	int		uinput_len = 0;
 	UErrorCode	status = U_ZERO_ERROR;
 		
-	UBool		uret = FALSE;
+	UBool		uret = false;
 		
 	intl_error_reset( NULL TSRMLS_CC );
 
