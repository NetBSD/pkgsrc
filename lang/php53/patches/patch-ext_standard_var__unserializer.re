$NetBSD: patch-ext_standard_var__unserializer.re,v 1.1.2.2 2014/10/25 15:55:51 tron Exp $

* Fix for CVE-2014-3669.

--- ext/standard/var_unserializer.re.orig	2014-08-13 19:22:50.000000000 +0000
+++ ext/standard/var_unserializer.re
@@ -339,7 +339,7 @@ static inline int object_custom(UNSERIAL
 
 	(*p) += 2;
 
-	if (datalen < 0 || (*p) + datalen >= max) {
+	if (datalen < 0 || (max - (*p)) <= datalen) {
 		zend_error(E_WARNING, "Insufficient data for unserializing - %ld required, %ld present", datalen, (long)(max - (*p)));
 		return 0;
 	}
