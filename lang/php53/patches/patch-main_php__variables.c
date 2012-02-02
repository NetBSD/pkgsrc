$NetBSD: patch-main_php__variables.c,v 1.3 2012/02/02 16:00:40 taca Exp $

Fix for "Critical PHP Remote Vulnerability Introduced in Fix for PHP Hashtable
Collision DOS" by revision 323007 from PHP's repository.

http://thexploit.com/sec/critical-php-remote-vulnerability-introduced-in-fix-for-php-hashtable-collision-dos/

--- main/php_variables.c.orig	2012-01-01 13:15:04.000000000 +0000
+++ main/php_variables.c
@@ -198,6 +198,9 @@ PHPAPI void php_register_variable_ex(cha
 						MAKE_STD_ZVAL(gpc_element);
 						array_init(gpc_element);
 						zend_symtable_update(symtable1, escaped_index, index_len + 1, &gpc_element, sizeof(zval *), (void **) &gpc_element_p);
+					} else {
+						efree(var_orig);
+						return;
 					}
 				}
 				if (index != escaped_index) {
