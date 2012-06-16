$NetBSD: patch-pdf.c,v 1.1 2012/06/16 02:59:00 taca Exp $

* Add support for PHP 5.4.x.

--- pdf.c.orig	1970-01-01 09:13:24.000000000 +0000
+++ pdf.c
@@ -1075,8 +1075,12 @@ PHP_FUNCTION(pdf_add_launchlink)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -1291,8 +1295,12 @@ PHP_FUNCTION(pdf_add_pdflink)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -1545,8 +1553,12 @@ PHP_FUNCTION(pdf_attach_file)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -1609,8 +1621,12 @@ PHP_FUNCTION(pdf_begin_document)
     vfilename = filename;
 #endif /* VIRTUAL_DIR */
 
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 
@@ -4773,8 +4789,12 @@ PHP_FUNCTION(pdf_load_iccprofile)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -4836,8 +4856,12 @@ PHP_FUNCTION(pdf_load_image)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -5037,8 +5061,12 @@ PHP_FUNCTION(pdf_open_ccitt)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -5102,8 +5130,12 @@ PHP_FUNCTION(pdf_open_file)
     vfilename = filename;
 #endif /* VIRTUAL_DIR */
 
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 
@@ -5222,8 +5254,12 @@ PHP_FUNCTION(pdf_open_image_file)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
@@ -5287,8 +5323,12 @@ PHP_FUNCTION(pdf_open_pdi)
 #endif /* VIRTUAL_DIR */
 
 #ifdef PDFLIB_CHECK_OPEN_BASEDIR
-    if (php_check_open_basedir(vfilename TSRMLS_CC) || (PG(safe_mode) &&
-            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+    if (php_check_open_basedir(vfilename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+	|| (PG(safe_mode) &&
+            !php_checkuid(vfilename, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+	) {
         RETURN_FALSE;
     }
 #endif /* PDFLIB_CHECK_OPEN_BASEDIR */
