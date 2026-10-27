$NetBSD: patch-ext_standard_var__unserializer.re,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- ext/standard/var_unserializer.re.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/standard/var_unserializer.re
@@ -372,6 +372,16 @@ static inline int process_nested_data(UN
 			return 0;
 		}
 
+		/* The members that incomplete_classes_only mode writes itself cannot be
+		 * told apart from that bookkeeping: reject them */
+		if (objprops && UNEXPECTED(BG(incomplete_classes_only)) && Z_TYPE_P(key) == IS_STRING
+				&& ((Z_STRLEN_P(key) == sizeof(MAGIC_MEMBER) - 1 && !memcmp(Z_STRVAL_P(key), MAGIC_MEMBER, sizeof(MAGIC_MEMBER) - 1))
+					|| (Z_STRLEN_P(key) == sizeof(MAGIC_MEMBER_SERIALIZED) - 1 && !memcmp(Z_STRVAL_P(key), MAGIC_MEMBER_SERIALIZED, sizeof(MAGIC_MEMBER_SERIALIZED) - 1)))) {
+			var_push_dtor_no_addref(var_hash, &key);
+			var_push_dtor_no_addref(var_hash, &data);
+			return 0;
+		}
+
 		if (!objprops) {
 			switch (Z_TYPE_P(key)) {
 			case IS_LONG:
@@ -418,7 +428,7 @@ static inline int finish_nested_data(UNS
 	return 1;
 }
 
-static inline int object_custom(UNSERIALIZE_PARAMETER, zend_class_entry *ce)
+static inline int object_custom(UNSERIALIZE_PARAMETER, zend_class_entry *ce, int keep_payload)
 {
 	long datalen;
 
@@ -431,7 +441,16 @@ static inline int object_custom(UNSERIAL
 		return 0;
 	}
 
-	if (ce->unserialize == NULL) {
+	if (keep_payload) {
+		/* The class was not resolved (see BG(incomplete_classes_only)): keep
+		 * the payload verbatim, so that the object serializes back unchanged */
+		zval *payload;
+
+		object_init_ex(*rval, ce);
+		MAKE_STD_ZVAL(payload);
+		ZVAL_STRINGL(payload, (char *) *p, datalen, 1);
+		zend_hash_update(Z_OBJPROP_PP(rval), MAGIC_MEMBER_SERIALIZED, sizeof(MAGIC_MEMBER_SERIALIZED), &payload, sizeof(payload), NULL);
+	} else if (ce->unserialize == NULL) {
 		zend_error(E_WARNING, "Class %s has no unserializer", ce->name);
 		object_init_ex(*rval, ce);
 	} else if (ce->unserialize(rval, ce, (const unsigned char*)*p, datalen, (zend_unserialize_data *)var_hash TSRMLS_CC) != SUCCESS) {
@@ -796,6 +815,14 @@ object ":" uiv ":" ["]	{
 	class_name = estrndup(class_name, len);
 
 	do {
+		if (BG(incomplete_classes_only)) {
+			/* Do not look the class up at all, so that no code (autoloader,
+			 * unserialize_callback_func, __wakeup(), unserialize()) can run */
+			incomplete_class = 1;
+			ce = PHP_IC_ENTRY;
+			break;
+		}
+
 		/* Try to find class directly */
 		BG(serialize_lock)++;
 		if (zend_lookup_class(class_name, len2, &pce TSRMLS_CC) == SUCCESS) {
@@ -875,7 +902,7 @@ object ":" uiv ":" ["]	{
 	if (custom_object) {
 		int ret;
 
-		ret = object_custom(UNSERIALIZE_PASSTHRU, ce);
+		ret = object_custom(UNSERIALIZE_PASSTHRU, ce, incomplete_class && BG(incomplete_classes_only));
 
 		if (ret && incomplete_class) {
 			php_store_class_name(*rval, class_name, len2);
