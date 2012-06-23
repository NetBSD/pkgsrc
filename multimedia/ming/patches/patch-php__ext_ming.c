$NetBSD: patch-php__ext_ming.c,v 1.1 2012/06/23 03:26:23 obache Exp $

* fixes build with PHP-5.4
 https://github.com/libming/libming/issues/9

--- php_ext/ming.c.orig	2011-10-26 06:33:18.000000000 +0000
+++ php_ext/ming.c
@@ -87,10 +87,17 @@ static SWFCXform getCXform(zval *id TSRM
 static SWFMatrix getMatrix(zval *id TSRMLS_DC);
 #endif
 
+#if PHP_API_VERSION < 20100412
 #define PHP_MING_FILE_CHK(file) \
 	if ((PG(safe_mode) && !php_checkuid((file), NULL, CHECKUID_CHECK_FILE_AND_DIR)) || php_check_open_basedir((file) TSRMLS_CC)) {	\
 		RETURN_FALSE;	\
-	}	\
+	}
+#else
+#define PHP_MING_FILE_CHK(file) \
+	if (php_check_open_basedir((file) TSRMLS_CC)) {	\
+		RETURN_FALSE;	\
+	}
+#endif
 
 /* {{{ proto void ming_setcubicthreshold (int threshold)
    Set cubic threshold (?) */
