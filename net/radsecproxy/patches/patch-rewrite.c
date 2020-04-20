$NetBSD: patch-rewrite.c,v 1.1 2020/04/20 00:43:29 joerg Exp $

--- rewrite.c.orig	2020-04-19 22:47:11.619604710 +0000
+++ rewrite.c
@@ -45,7 +45,7 @@ struct tlv *extractattr(char *nameval, c
     }
 
     s++;
-    if (isdigit(*s)) {
+    if (isdigit((unsigned char)*s)) {
         ival = atoi(s);
         ival = htonl(ival);
         len = 4;
