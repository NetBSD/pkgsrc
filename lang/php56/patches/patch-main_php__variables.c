$NetBSD: patch-main_php__variables.c,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- main/php_variables.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ main/php_variables.c
@@ -150,6 +150,13 @@ PHPAPI void php_register_variable_ex(cha
 				return;
 			}
 
+			/* Each level retains an array, so stop once over the memory limit */
+			if (ZEND_HAS_OOM()) {
+				zval_dtor(val);
+				free_alloca(var_orig, use_heap);
+				return;
+			}
+
 			ip++;
 			index_s = ip;
 			if (isspace(*ip)) {
@@ -308,6 +315,12 @@ static inline int add_post_vars(zval *ar
 					max_vars);
 			return FAILURE;
 		}
+		if (ZEND_HAS_OOM()) {
+			return FAILURE;
+		}
+	}
+	if (ZEND_HAS_OOM()) {
+		return FAILURE;
 	}
 
 	if (!eof && vars->str.c != vars->ptr) {
