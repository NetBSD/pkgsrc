$NetBSD: patch-libiconv_aliases.h,v 1.1 2012/04/19 21:02:11 joerg Exp $

--- libiconv/aliases.h.orig	2012-04-19 13:47:17.000000000 +0000
+++ libiconv/aliases.h
@@ -66,6 +66,7 @@ aliases_hash (register const char *str, 
   return hval + asso_values[(unsigned char) str[len - 1]];
 }
 
+static 
 #ifdef __GNUC__
 __inline
 #endif
