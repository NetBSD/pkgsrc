$NetBSD: patch-ext_intl_normalizer_normalizer__normalize.c,v 1.1 2020/11/08 23:51:18 otis Exp $

--- ext/intl/normalizer/normalizer_normalize.c.orig	2020-10-27 15:01:59.000000000 +0000
+++ ext/intl/normalizer/normalizer_normalize.c
@@ -90,7 +90,7 @@ static UBool intl_is_normalized(zend_lon
 	const UNormalizer2 *norm = intl_get_normalizer(form, err);
 
 	if(U_FAILURE(*err)) {
-		return FALSE;
+		return false;
 	}
 
 	return unorm2_isNormalized(norm, uinput, uinput_len, err);
@@ -261,7 +261,7 @@ PHP_FUNCTION( normalizer_is_normalized )
 	int		uinput_len = 0;
 	UErrorCode	status = U_ZERO_ERROR;
 
-	UBool		uret = FALSE;
+	UBool		uret = false;
 
 	intl_error_reset( NULL );
 
