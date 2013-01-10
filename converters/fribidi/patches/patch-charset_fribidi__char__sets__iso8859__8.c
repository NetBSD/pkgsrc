$NetBSD: patch-charset_fribidi__char__sets__iso8859__8.c,v 1.1 2013/01/10 06:59:57 mef Exp $


--- charset/fribidi-char-sets-iso8859-8.c.orig	2012-12-03 01:25:40.000000000 +0900
+++ charset/fribidi-char-sets-iso8859-8.c	2013-01-06 13:09:17.000000000 +0900
@@ -112,7 +112,7 @@ fribidi_unicode_to_iso8859_8_c (
     case FRIBIDI_CHAR_PDF:
       return (char) ISO_8859_8_PDF;
     }
-  return '?';
+  return (char) 0xbf;
 }
 
 /* Editor directions:
