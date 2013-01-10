$NetBSD: patch-charset_fribidi__char__sets__cp1256.c,v 1.1 2013/01/10 06:59:57 mef Exp $


--- charset/fribidi-char-sets-cp1256.c.orig	2012-12-03 01:25:40.000000000 +0900
+++ charset/fribidi-char-sets-cp1256.c	2013-01-06 13:07:15.000000000 +0900
@@ -214,7 +214,7 @@ fribidi_unicode_to_cp1256_c (
 	return (char) 0x99;
 
       default:
-	return '?';
+	return (char) 0xbf;
       }
 }
 
