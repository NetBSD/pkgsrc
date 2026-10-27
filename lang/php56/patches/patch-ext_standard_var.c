$NetBSD: patch-ext_standard_var.c,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- ext/standard/var.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/standard/var.c
@@ -768,6 +768,30 @@ static void php_var_serialize_intern(sma
 					ce = Z_OBJCE_P(struc);
 				}
 
+				if (ce && ce == PHP_IC_ENTRY && UNEXPECTED(BG(incomplete_classes_only))) {
+					/* C: value kept by php_var_unserialize(), see BG(incomplete_classes_only) */
+					zval **payload;
+					char *class_name;
+					zend_uint name_len;
+
+					if (zend_hash_find(Z_OBJPROP_P(struc), MAGIC_MEMBER_SERIALIZED, sizeof(MAGIC_MEMBER_SERIALIZED), (void **) &payload) == SUCCESS
+							&& Z_TYPE_PP(payload) == IS_STRING
+							&& (class_name = php_lookup_class_name(struc, &name_len)) != NULL) {
+						smart_str_appendl(buf, "C:", 2);
+						smart_str_append_long(buf, (int)name_len);
+						smart_str_appendl(buf, ":\"", 2);
+						smart_str_appendl(buf, class_name, name_len);
+						smart_str_appendl(buf, "\":", 2);
+
+						smart_str_append_long(buf, (int)Z_STRLEN_PP(payload));
+						smart_str_appendl(buf, ":{", 2);
+						smart_str_appendl(buf, Z_STRVAL_PP(payload), Z_STRLEN_PP(payload));
+						smart_str_appendc(buf, '}');
+						efree(class_name);
+						return;
+					}
+				}
+
 				if (ce && ce->serialize != NULL) {
 					/* has custom handler */
 					unsigned char *serialized_data = NULL;
