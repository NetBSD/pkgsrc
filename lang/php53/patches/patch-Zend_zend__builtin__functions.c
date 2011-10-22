$NetBSD: patch-Zend_zend__builtin__functions.c,v 1.2.2.2 2011/10/22 07:01:25 sbd Exp $

* Fix for CVE-2011-3379 from r317183 from PHP's repository.

--- Zend/zend_builtin_functions.c.orig	2011-08-08 14:54:50.000000000 +0000
+++ Zend/zend_builtin_functions.c
@@ -816,13 +816,19 @@ static void is_a_impl(INTERNAL_FUNCTION_
 	int class_name_len;
 	zend_class_entry *instance_ce;
 	zend_class_entry **ce;
+	zend_bool allow_string = only_subclass;
 	zend_bool retval;
 
-	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zs", &obj, &class_name, &class_name_len) == FAILURE) {
+	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zs|b", &obj, &class_name, &class_name_len, &allow_string) == FAILURE) {
 		return;
 	}
-	
-	if (Z_TYPE_P(obj) == IS_STRING) {
+	/*
+	   allow_string - is_a default is no, is_subclass_of is yes. 
+	   if it's allowed, then the autoloader will be called if the class does not exist.
+	   default behaviour is different, as 'is_a' usage is normally to test mixed return values 
+	*/
+
+	if (allow_string && Z_TYPE_P(obj) == IS_STRING) {
 		zend_class_entry **the_ce;
 		if (zend_lookup_class(Z_STRVAL_P(obj), Z_STRLEN_P(obj), &the_ce TSRMLS_CC) == FAILURE) {
 			RETURN_FALSE;
