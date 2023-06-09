$NetBSD: patch-base64.c,v 1.1 2023/06/09 19:38:24 schmonz Exp $

Squelch -Wdeprecated-non-prototype warnings.

--- base64.c.orig	2014-11-25 13:40:32.000000000 +0000
+++ base64.c
@@ -3,9 +3,7 @@
 char b64string[] =
   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
-long base64_encode(to, from, len)
-     char *to, *from;
-     unsigned int len;
+long base64_encode(char *to, char *from, unsigned int len)
 {
   char *fromp = from;
   char *top = to;
@@ -60,9 +58,7 @@ long base64_encode(to, from, len)
 /* location of c or null into p.                  */
 #define badchar(c,p) (!(p = memchr(b64string, c, 64)))
 
-long base64_decode(to, from, len)
-     char *to, *from;
-     unsigned int len;
+long base64_decode(char *to, char *from, unsigned int len)
 {
   char *fromp = from;
   char *top = to;
