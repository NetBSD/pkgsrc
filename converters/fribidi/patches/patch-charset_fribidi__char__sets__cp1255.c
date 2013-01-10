$NetBSD: patch-charset_fribidi__char__sets__cp1255.c,v 1.1 2013/01/10 06:59:56 mef Exp $


--- charset/fribidi-char-sets-cp1255.c.orig	2012-12-03 01:25:40.000000000 +0900
+++ charset/fribidi-char-sets-cp1255.c	2013-01-06 13:06:42.000000000 +0900
@@ -108,7 +108,7 @@ fribidi_unicode_to_cp1255_c (
   else if (uch < 256)
     return (char) uch;
   else
-    return '?';
+    return (char) 0xbf;
 }
 
 /* Editor directions:
