$NetBSD: patch-ext_spl_spl__array.c,v 1.1 2014/07/13 15:23:42 taca Exp $

Fix for CVE-2014-4698.

--- ext/spl/spl_array.c.orig	2014-06-25 13:06:23.000000000 +0000
+++ ext/spl/spl_array.c
@@ -1733,6 +1733,7 @@ SPL_METHOD(Array, unserialize)
 	const unsigned char *p, *s;
 	php_unserialize_data_t var_hash;
 	zval *pmembers, *pflags = NULL;
+	HashTable *aht;
 	long flags;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &buf, &buf_len) == FAILURE) {
@@ -1744,6 +1745,12 @@ SPL_METHOD(Array, unserialize)
 		return;
 	}
 
+	aht = spl_array_get_hash_table(intern, 0 TSRMLS_CC);
+	if (aht->nApplyCount > 0) {
+		zend_error(E_WARNING, "Modification of ArrayObject during sorting is prohibited");
+		return;
+	}
+
 	/* storage */
 	s = p = (const unsigned char*)buf;
 	PHP_VAR_UNSERIALIZE_INIT(var_hash);
