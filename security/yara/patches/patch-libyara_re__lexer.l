$NetBSD: patch-libyara_re__lexer.l,v 1.1 2017/11/15 18:22:22 he Exp $

Ensure we adhere to valid value domain for isxxxx() function/macro.

--- libyara/re_lexer.l.orig	2017-11-10 11:21:21.000000000 +0000
+++ libyara/re_lexer.l
@@ -488,7 +488,7 @@ int escaped_char_value(
   switch(text[1])
   {
   case 'x':
-    if (!isxdigit(text[2]) || !isxdigit(text[3]))
+    if (!isxdigit((unsigned char)text[2]) || !isxdigit((unsigned char)text[3]))
       return 0;
     hex[0] = text[2];
     hex[1] = text[3];
