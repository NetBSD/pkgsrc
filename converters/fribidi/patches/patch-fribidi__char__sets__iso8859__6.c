$NetBSD: patch-fribidi__char__sets__iso8859__6.c,v 1.1 2012/01/23 08:07:17 joerg Exp $

--- fribidi_char_sets_iso8859_6.c.orig	2012-01-22 21:53:52.000000000 +0000
+++ fribidi_char_sets_iso8859_6.c
@@ -66,10 +66,8 @@ fribidi_unicode_to_iso8859_6_c (FriBidiC
     return (char) 0xac;
   else if (uch == 0x061b)
     return (char) 0xbb;
-  else if (uch == 0x061f)
-    return (char) 0xbf;
   else
-    return '¿';
+    return (char) 0xbf;
 }
 
 int
