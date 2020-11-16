$NetBSD: patch-ext_intl_locale_locale__methods.c,v 1.1 2020/11/16 12:10:05 ryoon Exp $

--- ext/intl/locale/locale_methods.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/intl/locale/locale_methods.c
@@ -211,7 +211,7 @@ static int getSingletonPos(const char* s
    Get default locale */
 PHP_NAMED_FUNCTION(zif_locale_get_default)
 {
-	RETURN_STRING( intl_locale_get_default( TSRMLS_C ), TRUE );
+	RETURN_STRING( intl_locale_get_default( TSRMLS_C ), true );
 }
 
 /* }}} */
@@ -409,12 +409,12 @@ static void get_icu_value_src_php( char*
 		if( tag_value){
 			efree( tag_value);
 		}
-		RETURN_STRING( empty_result , TRUE);
+		RETURN_STRING( empty_result , true);
 	}
 
 	/* value found */
 	if( tag_value){
-		RETURN_STRING( tag_value , FALSE);
+		RETURN_STRING( tag_value , false);
 	}
 
 	/* Error encountered while fetching the value */
@@ -599,7 +599,7 @@ static void get_icu_disp_value_src_php( 
 		RETURN_FALSE;
 	}
 
-	RETVAL_STRINGL( utf8value, utf8value_len , FALSE);
+	RETVAL_STRINGL( utf8value, utf8value_len , false);
 
 }
 /* }}} */
@@ -1062,11 +1062,11 @@ static int add_array_entry(const char* l
 			}
 			cur_key_name = (char*)ecalloc( 25,  25);
 			sprintf( cur_key_name , "%s%d", key_name , cnt++);
-			add_assoc_string( hash_arr, cur_key_name , token ,TRUE );
+			add_assoc_string( hash_arr, cur_key_name , token ,true );
 			/* tokenize on the "_" or "-" and stop  at singleton if any */
 			while( (token = php_strtok_r(NULL , DELIMITER , &last_ptr)) && (strlen(token)>1) ){
 				sprintf( cur_key_name , "%s%d", key_name , cnt++);
-				add_assoc_string( hash_arr, cur_key_name , token , TRUE );
+				add_assoc_string( hash_arr, cur_key_name , token , true );
 			}
 /*
 			if( strcmp(key_name, LOC_PRIVATE_TAG) == 0 ){
@@ -1075,7 +1075,7 @@ static int add_array_entry(const char* l
 		}
 	} else {
 		if( result == 1 ){
-			add_assoc_string( hash_arr, key_name , key_value , TRUE );
+			add_assoc_string( hash_arr, key_name , key_value , true );
 			cur_result = 1;
 		}
 	}
@@ -1124,7 +1124,7 @@ PHP_FUNCTION(locale_parse)
 
 	grOffset =  findOffset( LOC_GRANDFATHERED , loc_name );
 	if( grOffset >= 0 ){
-		add_assoc_string( return_value , LOC_GRANDFATHERED_LANG_TAG , estrdup(loc_name) ,FALSE );
+		add_assoc_string( return_value , LOC_GRANDFATHERED_LANG_TAG , estrdup(loc_name) ,false );
 	}
 	else{
 		/* Not grandfathered */
@@ -1182,10 +1182,10 @@ PHP_FUNCTION(locale_get_all_variants)
 		if( result > 0 && variant){
 			/* Tokenize on the "_" or "-" */
 			token = php_strtok_r( variant , DELIMITER , &saved_ptr);
-			add_next_index_stringl( return_value, token , strlen(token) ,TRUE );
+			add_next_index_stringl( return_value, token , strlen(token) ,true );
 			/* tokenize on the "_" or "-" and stop  at singleton if any	*/
 			while( (token = php_strtok_r(NULL , DELIMITER, &saved_ptr)) && (strlen(token)>1) ){
- 				add_next_index_stringl( return_value, token , strlen(token) ,TRUE );
+ 				add_next_index_stringl( return_value, token , strlen(token) ,true );
 			}
 		}
 		if( variant ){
