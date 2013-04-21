$NetBSD: patch-src_canna.c,v 1.1 2013/04/21 15:39:59 joerg Exp $

--- src/canna.c.orig	1995-02-17 07:47:37.000000000 +0000
+++ src/canna.c
@@ -1318,7 +1318,7 @@ int len,pos,rev,*clen,*cpos,*crev;
   unsigned char *q = p;
   
   *clen = *cpos = *crev = 0;
-  if (len == 0) return;
+  if (len == 0) return 0;
   while (q < p + pos) {
     (*clen)++;
     (*cpos)++;
