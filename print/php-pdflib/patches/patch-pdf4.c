$NetBSD: patch-pdf4.c,v 1.1 2012/06/16 02:59:00 taca Exp $

* Add support for PHP 5.4.x.

--- pdf4.c.orig	1970-01-01 09:13:24.000000000 +0000
+++ pdf4.c
@@ -1846,7 +1846,11 @@ static void _php_pdf_open_image(INTERNAL
 	image = Z_STRVAL_PP(arg2);
 #endif  
 
-	if (php_check_open_basedir(image TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(image TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+		|| (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+		) {
 		RETURN_FALSE;
 	}
 
@@ -1923,7 +1927,11 @@ PHP_FUNCTION(pdf_open_image_file)
 	image = Z_STRVAL_PP(arg3);
 #endif  
 
-	if (php_check_open_basedir(image TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(image TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+		|| (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+		) {
 		RETURN_FALSE;
 	}
 
@@ -2345,7 +2353,11 @@ PHP_FUNCTION(pdf_open_file)
 		convert_to_string_ex(arg2);
 		filename = Z_STRVAL_PP(arg2);
 
-		if (php_check_open_basedir(filename TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(filename, "wb+", CHECKUID_CHECK_MODE_PARAM))) {
+		if (php_check_open_basedir(filename TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+			|| (PG(safe_mode) && !php_checkuid(filename, "wb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+			) {
 			RETURN_FALSE;
 		}
 		if (php_check_open_basedir(filename TSRMLS_CC)) {
@@ -2564,7 +2576,11 @@ PHP_FUNCTION(pdf_open_ccitt)
 	image = Z_STRVAL_PP(arg2);
 #endif  
 
-	if (php_check_open_basedir(image TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(image TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+		|| (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+		) {
 		RETURN_FALSE;
 	}
 
@@ -2617,7 +2633,11 @@ PHP_FUNCTION(pdf_open_image)
 	image = Z_STRVAL_PP(arg4);
 #endif  
 
-	if (php_check_open_basedir(image TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(image TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+		|| (PG(safe_mode) && !php_checkuid(image, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+		) {
 		RETURN_FALSE;
 	}
 
@@ -2659,7 +2679,11 @@ PHP_FUNCTION(pdf_attach_file)
 	convert_to_string_ex(arg9);
 	convert_to_string_ex(arg10);
 
-	if (php_check_open_basedir(Z_STRVAL_PP(arg6) TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(Z_STRVAL_PP(arg6), "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(Z_STRVAL_PP(arg6) TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+		|| (PG(safe_mode) && !php_checkuid(Z_STRVAL_PP(arg6), "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+		) {
 		RETURN_FALSE;
 	}
 
@@ -2803,7 +2827,11 @@ PHP_FUNCTION(pdf_open_pdi)
 	file = Z_STRVAL_PP(arg2);
 #endif  
 
-	if (php_check_open_basedir(file TSRMLS_CC) || (PG(safe_mode) && !php_checkuid(file, "rb+", CHECKUID_CHECK_MODE_PARAM))) {
+	if (php_check_open_basedir(file TSRMLS_CC)
+#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 4
+		|| (PG(safe_mode) && !php_checkuid(file, "rb+", CHECKUID_CHECK_MODE_PARAM))
+#endif
+		) {
 		RETURN_FALSE;
 	}
 
