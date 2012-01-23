$NetBSD: patch-fribidi__char__sets__isiri__3342.c,v 1.1 2012/01/23 08:07:17 joerg Exp $

--- fribidi_char_sets_isiri_3342.c.orig	2012-01-22 21:58:31.000000000 +0000
+++ fribidi_char_sets_isiri_3342.c
@@ -213,7 +213,7 @@ fribidi_unicode_to_isiri_3342_c (FriBidi
       case 0x200D:
 	return (char) 0xA2;
       default:
-	return '¿';
+	return (char) 0xbf;
       }
 }
 
