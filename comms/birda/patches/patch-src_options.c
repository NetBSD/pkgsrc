$NetBSD: patch-src_options.c,v 1.1 2013/10/10 00:02:17 joerg Exp $

--- src/options.c.orig	2013-10-09 23:05:27.000000000 +0000
+++ src/options.c
@@ -223,7 +223,7 @@ static void showDiscovered(int addr, int
 
   if(charset==CHARSET_UNICODE) {
     /* Strip the high byte */
-    for(i=0;2*i<len;i+=2) namebuf[i++]=name[2*i];
+    for(i=0;2*i<len;++i) namebuf[i]=name[2*i];
     namebuf[i]=0;
   } else {
     memcpy(namebuf,name,len);
