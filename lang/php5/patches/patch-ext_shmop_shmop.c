$NetBSD: patch-ext_shmop_shmop.c,v 1.1.2.2 2011/03/22 06:22:18 sbd Exp $

Fix for CVE-2011-1092.

--- ext/shmop/shmop.c.orig	2010-01-03 09:23:27.000000000 +0000
+++ ext/shmop/shmop.c
@@ -223,7 +223,7 @@ PHP_FUNCTION(shmop_read)
 		RETURN_FALSE;
 	}
 
-	if (start + count > shmop->size || count < 0) {
+	if (count < 0 || start > (INT_MAX - count) || start + count > shmop->size) {
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, "count is out of range");
 		RETURN_FALSE;
 	}
