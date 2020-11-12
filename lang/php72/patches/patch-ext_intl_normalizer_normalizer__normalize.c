$NetBSD: patch-ext_intl_normalizer_normalizer__normalize.c,v 1.2 2020/11/12 10:59:05 markd Exp $

Use stdbool true/false macros.

--- ext/intl/normalizer/normalizer_normalize.c.orig	2020-09-30 05:15:54.000000000 +0000
+++ ext/intl/normalizer/normalizer_normalize.c
@@ -178,7 +178,7 @@ PHP_FUNCTION( normalizer_is_normalized )
 	int		uinput_len = 0;
 	UErrorCode	status = U_ZERO_ERROR;
 
-	UBool		uret = FALSE;
+	UBool		uret = false;
 
 	intl_error_reset( NULL );
 
