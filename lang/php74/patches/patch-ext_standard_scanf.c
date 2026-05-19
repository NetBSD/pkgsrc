$NetBSD: patch-ext_standard_scanf.c,v 1.1 2026/05/19 10:12:22 jperkin Exp $

Fix for modern C.

--- ext/standard/scanf.c.orig	2026-05-19 09:55:56.176982562 +0000
+++ ext/standard/scanf.c
@@ -585,7 +585,7 @@ PHPAPI int php_sscanf_internal( char *st
 	int  base = 0;
 	int  underflow = 0;
 	size_t width;
-	zend_long (*fn)() = NULL;
+	zend_long (*fn)(const char *, char **, int) = NULL;
 	char *ch, sch;
 	int  flags;
 	char buf[64];	/* Temporary buffer to hold scanned number
@@ -750,29 +750,29 @@ literal:
 			case 'D':
 				op = 'i';
 				base = 10;
-				fn = (zend_long (*)())ZEND_STRTOL_PTR;
+				fn = (zend_long (*)(const char *, char **, int))ZEND_STRTOL_PTR;
 				break;
 			case 'i':
 				op = 'i';
 				base = 0;
-				fn = (zend_long (*)())ZEND_STRTOL_PTR;
+				fn = (zend_long (*)(const char *, char **, int))ZEND_STRTOL_PTR;
 				break;
 			case 'o':
 				op = 'i';
 				base = 8;
-				fn = (zend_long (*)())ZEND_STRTOL_PTR;
+				fn = (zend_long (*)(const char *, char **, int))ZEND_STRTOL_PTR;
 				break;
 			case 'x':
 			case 'X':
 				op = 'i';
 				base = 16;
-				fn = (zend_long (*)())ZEND_STRTOL_PTR;
+				fn = (zend_long (*)(const char *, char **, int))ZEND_STRTOL_PTR;
 				break;
 			case 'u':
 				op = 'i';
 				base = 10;
 				flags |= SCAN_UNSIGNED;
-				fn = (zend_long (*)())ZEND_STRTOUL_PTR;
+				fn = (zend_long (*)(const char *, char **, int))ZEND_STRTOUL_PTR;
 				break;
 
 			case 'f':
