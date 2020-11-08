$NetBSD: patch-ext_intl_dateformat_dateformat__attr.c,v 1.2 2020/11/08 23:55:44 otis Exp $

Use stdbool true/false macros.

--- ext/intl/dateformat/dateformat_attr.c.orig	2020-10-27 15:01:59.000000000 +0000
+++ ext/intl/dateformat/dateformat_attr.c
@@ -88,7 +88,7 @@ PHP_FUNCTION( datefmt_get_pattern )
 	UChar  value_buf[64];
 	uint32_t    length = USIZE( value_buf );
 	UChar* value  = value_buf;
-	zend_bool   is_pattern_localized =FALSE;
+	zend_bool   is_pattern_localized =false;
 
 	DATE_FORMAT_METHOD_INIT_VARS;
 
@@ -131,7 +131,7 @@ PHP_FUNCTION( datefmt_set_pattern )
 	size_t      value_len = 0;
 	int32_t     slength = 0;
 	UChar*	    svalue  = NULL;
-	zend_bool   is_pattern_localized =FALSE;
+	zend_bool   is_pattern_localized =false;
 
 
 	DATE_FORMAT_METHOD_INIT_VARS;
@@ -227,7 +227,7 @@ PHP_FUNCTION( datefmt_is_lenient )
  */
 PHP_FUNCTION( datefmt_set_lenient )
 {
-	zend_bool isLenient  = FALSE;
+	zend_bool isLenient  = false;
 
 	DATE_FORMAT_METHOD_INIT_VARS;
 
