$NetBSD: patch-pdf7.c,v 1.1 2012/06/16 02:59:00 taca Exp $

* Add support for PHP 5.4.x.

--- pdf7.c.orig	1970-01-01 09:13:24.000000000 +0000
+++ pdf7.c
@@ -541,8 +541,12 @@ PHP_FUNCTION(pdf_open_pdi)
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
     if (vfilename && *vfilename) {
-	if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-		!php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	    || (PG(safe_mode) &&
+		!php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	    ) {
 	    RETURN_FALSE;
     }
     }
