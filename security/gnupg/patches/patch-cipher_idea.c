$NetBSD: patch-cipher_idea.c,v 1.1 2013/01/07 21:53:53 wiz Exp $

Fix for big-endian, from
http://bugs.g10code.com/gnupg/issue1461

--- cipher/idea.c.orig	2012-12-20 17:22:26.000000000 +0000
+++ cipher/idea.c
@@ -201,7 +201,7 @@ cipher( byte *outbuf, const byte *inbuf,
     x2 = *in++;
     x3 = *in++;
     x4 = *in;
-  #ifndef WORDS_BIGENDIAN
+  #ifndef BIG_ENDIAN_HOST
     x1 = (x1>>8) | (x1<<8);
     x2 = (x2>>8) | (x2<<8);
     x3 = (x3>>8) | (x3<<8);
@@ -234,7 +234,7 @@ cipher( byte *outbuf, const byte *inbuf,
     MUL(x4, *key);
 
     out = (u16*)outbuf;
-  #ifndef WORDS_BIGENDIAN
+  #ifndef BIG_ENDIAN_HOST
     *out++ = (x1>>8) | (x1<<8);
     *out++ = (x3>>8) | (x3<<8);
     *out++ = (x2>>8) | (x2<<8);
