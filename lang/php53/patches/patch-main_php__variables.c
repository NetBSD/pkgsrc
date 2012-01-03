$NetBSD: patch-main_php__variables.c,v 1.1 2012/01/03 16:23:14 taca Exp $

* Fix for http://www.ocert.org/advisories/ocert-2011-003.html
  from r321038 from PHP's repository.

--- main/php_variables.c.orig	2011-01-01 02:19:59.000000000 +0000
+++ main/php_variables.c
@@ -191,6 +191,9 @@ PHPAPI void php_register_variable_ex(cha
 				}
 				if (zend_symtable_find(symtable1, escaped_index, index_len + 1, (void **) &gpc_element_p) == FAILURE
 					|| Z_TYPE_PP(gpc_element_p) != IS_ARRAY) {
+					if (zend_hash_num_elements(symtable1) >= PG(max_input_vars)) {
+						php_error_docref(NULL TSRMLS_CC, E_ERROR, "Input variables exceeded %ld. To increase the limit change max_input_vars in php.ini.", PG(max_input_vars));
+					}
 					MAKE_STD_ZVAL(gpc_element);
 					array_init(gpc_element);
 					zend_symtable_update(symtable1, escaped_index, index_len + 1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p);
@@ -236,6 +239,9 @@ plain_var:
 				zend_symtable_exists(symtable1, escaped_index, index_len + 1)) {
 				zval_ptr_dtor(&gpc_element);
 			} else {
+				if (zend_hash_num_elements(symtable1) >= PG(max_input_vars)) {
+					php_error_docref(NULL TSRMLS_CC, E_ERROR, "Input variables exceeded %ld. To increase the limit change max_input_vars in php.ini.", PG(max_input_vars));
+				}
 				zend_symtable_update(symtable1, escaped_index, index_len + 1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p);
 			}
 			if (escaped_index != index) {
