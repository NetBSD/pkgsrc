$NetBSD: patch-fribidi__char__sets__cp1255.c,v 1.1 2012/01/23 08:07:17 joerg Exp $

--- fribidi_char_sets_cp1255.c.orig	2012-01-22 21:57:13.000000000 +0000
+++ fribidi_char_sets_cp1255.c
@@ -93,7 +93,7 @@ fribidi_unicode_to_cp1255_c (FriBidiChar
   else if (uch < 256)
     return (char) uch;
   else
-    return '¿';
+    return (char) 0xbf;
 }
 
 int
