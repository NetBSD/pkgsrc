$NetBSD: patch-ext_date_php_date.c,v 1.1 2015/02/18 11:14:15 sevan Exp $

Fix bug #68942 (Use after free vulnerability in unserialize() with DateTimeZone)

--- ext/date/php_date.c.orig	2015-01-21 10:23:27.000000000 +0000
+++ ext/date/php_date.c
@@ -2779,12 +2779,9 @@ static int php_date_initialize_from_hash
 	timelib_tzinfo   *tzi;
 	php_timezone_obj *tzobj;
 
-	if (zend_hash_find(myht, "date", 5, (void**) &z_date) == SUCCESS) {
-		convert_to_string(*z_date);
-		if (zend_hash_find(myht, "timezone_type", 14, (void**) &z_timezone_type) == SUCCESS) {
-			convert_to_long(*z_timezone_type);
-			if (zend_hash_find(myht, "timezone", 9, (void**) &z_timezone) == SUCCESS) {
-				convert_to_string(*z_timezone);
+	if (zend_hash_find(myht, "date", 5, (void**) &z_date) == SUCCESS && Z_TYPE_PP(z_date) == IS_STRING) {
+		if (zend_hash_find(myht, "timezone_type", 14, (void**) &z_timezone_type) == SUCCESS && Z_TYPE_PP(z_timezone_type) == IS_LONG) {
+			if (zend_hash_find(myht, "timezone", 9, (void**) &z_timezone) == SUCCESS && Z_TYPE_PP(z_timezone) == IS_STRING) {
 
 				switch (Z_LVAL_PP(z_timezone_type)) {
 					case TIMELIB_ZONETYPE_OFFSET:
@@ -2799,7 +2796,6 @@ static int php_date_initialize_from_hash
 
 					case TIMELIB_ZONETYPE_ID: {
 						int ret;
-						convert_to_string(*z_timezone);
 
 						tzi = php_date_parse_tzfile(Z_STRVAL_PP(z_timezone), DATE_TIMEZONEDB TSRMLS_CC);
 
@@ -3716,9 +3712,8 @@ static int php_date_timezone_initialize_
 	zval            **z_timezone = NULL;
 	zval            **z_timezone_type = NULL;
 
-	if (zend_hash_find(myht, "timezone_type", 14, (void**) &z_timezone_type) == SUCCESS) {
+	if (zend_hash_find(myht, "timezone_type", 14, (void**) &z_timezone_type) == SUCCESS && Z_TYPE_PP(z_timezone_type) == IS_LONG) {
 		if (zend_hash_find(myht, "timezone", 9, (void**) &z_timezone) == SUCCESS) {
-			convert_to_long(*z_timezone_type);
 			if (SUCCESS == timezone_initialize(*tzobj, Z_STRVAL_PP(z_timezone) TSRMLS_CC)) {
 				return SUCCESS;
 			}
@@ -3743,7 +3738,9 @@ PHP_METHOD(DateTimeZone, __set_state)
 
 	php_date_instantiate(date_ce_timezone, return_value TSRMLS_CC);
 	tzobj = (php_timezone_obj *) zend_object_store_get_object(return_value TSRMLS_CC);
-	php_date_timezone_initialize_from_hash(&return_value, &tzobj, myht TSRMLS_CC);
+	if(php_date_timezone_initialize_from_hash(&return_value, &tzobj, myht TSRMLS_CC) != SUCCESS) {
+		php_error_docref(NULL, E_ERROR, "Timezone initialization failed");
+	}
 }
 /* }}} */
 
@@ -3759,7 +3756,9 @@ PHP_METHOD(DateTimeZone, __wakeup)
 
 	myht = Z_OBJPROP_P(object);
 	
-	php_date_timezone_initialize_from_hash(&return_value, &tzobj, myht TSRMLS_CC);
+	if(php_date_timezone_initialize_from_hash(&return_value, &tzobj, myht TSRMLS_CC) != SUCCESS) {
+		php_error_docref(NULL, E_ERROR, "Timezone initialization failed");
+	}
 }
 /* }}} */
 
