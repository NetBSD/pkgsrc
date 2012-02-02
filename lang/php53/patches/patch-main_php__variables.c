$NetBSD: patch-main_php__variables.c,v 1.4 2012/02/02 16:19:44 taca Exp $

* Fix for "Critical PHP Remote Vulnerability Introduced in Fix for PHP Hashtable
  Collision DOS" by revision 323007 from PHP's repository.

http://thexploit.com/sec/critical-php-remote-vulnerability-introduced-in-fix-for-php-hashtable-collision-dos/

* And more fix for memory leaks by revision 323013 from PHP's repository.

--- main/php_variables.c.orig	2012-01-01 13:15:04.000000000 +0000
+++ main/php_variables.c
@@ -182,7 +182,12 @@ PHPAPI void php_register_variable_ex(cha
 			if (!index) {
 				MAKE_STD_ZVAL(gpc_element);
 				array_init(gpc_element);
-				zend_hash_next_index_insert(symtable1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p);
+				if (zend_hash_next_index_insert(symtable1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p) == FAILURE) {
+					zval_ptr_dtor(&gpc_element);
+					zval_dtor(val);
+					efree(var_orig);
+					return;
+				}
 			} else {
 				if (PG(magic_quotes_gpc)) {
 					escaped_index = php_addslashes(index, index_len, &index_len, 0 TSRMLS_CC);
@@ -198,6 +203,13 @@ PHPAPI void php_register_variable_ex(cha
 						MAKE_STD_ZVAL(gpc_element);
 						array_init(gpc_element);
 						zend_symtable_update(symtable1, escaped_index, index_len + 1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p);
+					} else {
+						if (index != escaped_index) {
+							efree(escaped_index);
+						}
+						zval_dtor(val);
+						efree(var_orig);
+						return;
 					}
 				}
 				if (index != escaped_index) {
@@ -223,7 +235,9 @@ plain_var:
 		gpc_element->value = val->value;
 		Z_TYPE_P(gpc_element) = Z_TYPE_P(val);
 		if (!index) {
-			zend_hash_next_index_insert(symtable1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p);
+			if (zend_hash_next_index_insert(symtable1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p) == FAILURE) {
+				zval_ptr_dtor(&gpc_element);
+			}
 		} else {
 			if (PG(magic_quotes_gpc)) { 
 				escaped_index = php_addslashes(index, index_len, &index_len, 0 TSRMLS_CC);
