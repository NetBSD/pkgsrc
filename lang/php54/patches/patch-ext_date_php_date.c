$NetBSD: patch-ext_date_php_date.c,v 1.1 2015/02/18 11:04:03 sevan Exp $

Fix bug #68942 (Use after free vulnerability in unserialize() with DateTimeZone)

--- ext/date/php_date.c.orig	2015-01-20 20:06:02.000000000 +0000
+++ ext/date/php_date.c
@@ -2575,12 +2575,9 @@ static int php_date_initialize_from_hash
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
@@ -2595,7 +2592,6 @@ static int php_date_initialize_from_hash
 
 					case TIMELIB_ZONETYPE_ID: {
 						int ret;
-						convert_to_string(*z_timezone);
 
 						tzi = php_date_parse_tzfile(Z_STRVAL_PP(z_timezone), DATE_TIMEZONEDB TSRMLS_CC);
 
