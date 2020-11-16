$NetBSD: patch-ext_intl_collator_collator__convert.c,v 1.1 2020/11/16 12:10:05 ryoon Exp $

* Fix build with textproc/icu-68.1.

--- ext/intl/collator/collator_convert.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/collator/collator_convert.c
@@ -68,7 +68,7 @@ static void collator_convert_hash_item_f
 
 	/* Update current hash item with the converted value. */
 	MAKE_STD_ZVAL( znew_val );
-	ZVAL_STRINGL( znew_val, (char*)new_val, UBYTES(new_val_len), FALSE );
+	ZVAL_STRINGL( znew_val, (char*)new_val, UBYTES(new_val_len), false );
 
 	if( hashKeyType == HASH_KEY_IS_STRING )
 	{
@@ -113,7 +113,7 @@ static void collator_convert_hash_item_f
 
 	/* Update current hash item with the converted value. */
 	MAKE_STD_ZVAL( znew_val );
-	ZVAL_STRINGL( znew_val, (char*)new_val, new_val_len, FALSE );
+	ZVAL_STRINGL( znew_val, (char*)new_val, new_val_len, false );
 
 	if( hashKeyType == HASH_KEY_IS_STRING )
 	{
@@ -201,7 +201,7 @@ zval* collator_convert_zstr_utf16_to_utf
 		php_error( E_WARNING, "Error converting utf16 to utf8 in collator_convert_zval_utf16_to_utf8()" );
 
 	ALLOC_INIT_ZVAL( utf8_zval );
-	ZVAL_STRINGL( utf8_zval, str, str_len, FALSE );
+	ZVAL_STRINGL( utf8_zval, str, str_len, false );
 
 	return utf8_zval;
 }
@@ -232,7 +232,7 @@ zval* collator_convert_zstr_utf8_to_utf1
 
 	/* Set string. */
 	ALLOC_INIT_ZVAL( zstr );
-	ZVAL_STRINGL( zstr, (char*)ustr, UBYTES(ustr_len), FALSE );
+	ZVAL_STRINGL( zstr, (char*)ustr, UBYTES(ustr_len), false );
 
 	return zstr;
 }
@@ -307,7 +307,7 @@ zval* collator_convert_object_to_string(
 	zval_dtor( zstr );
 
 	/* Set string. */
-	ZVAL_STRINGL( zstr, (char*)ustr, UBYTES(ustr_len), FALSE );
+	ZVAL_STRINGL( zstr, (char*)ustr, UBYTES(ustr_len), false );
 
 	/* Don't free ustr cause it's set in zstr without copy.
 	 * efree( ustr );
