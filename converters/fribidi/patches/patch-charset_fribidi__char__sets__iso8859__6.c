$NetBSD: patch-charset_fribidi__char__sets__iso8859__6.c,v 1.1 2013/01/10 06:59:57 mef Exp $


--- charset/fribidi-char-sets-iso8859-6.c.orig	2012-12-03 01:25:40.000000000 +0900
+++ charset/fribidi-char-sets-iso8859-6.c	2013-01-06 13:08:29.000000000 +0900
@@ -70,10 +70,8 @@ fribidi_unicode_to_iso8859_6_c (
     return (char) 0xac;
   else if (uch == 0x061b)
     return (char) 0xbb;
-  else if (uch == 0x061f)
-    return (char) 0xbf;
   else
-    return '?';
+    return (char) 0xbf;
 }
 
 /* Editor directions:
