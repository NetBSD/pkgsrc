$NetBSD: patch-testapi.c,v 1.1 2012/01/23 08:10:56 joerg Exp $

--- testapi.c.orig	2012-01-20 23:15:01.000000000 +0000
+++ testapi.c
@@ -291,7 +291,7 @@ static void des_long(int no ATTRIBUTE_UN
 static xmlChar gen_xmlChar(int no, int nr ATTRIBUTE_UNUSED) {
     if (no == 0) return('a');
     if (no == 1) return(' ');
-    if (no == 2) return((xmlChar) 'ø');
+    if (no == 2) return((xmlChar)0xf8);
     return(0);
 }
 
