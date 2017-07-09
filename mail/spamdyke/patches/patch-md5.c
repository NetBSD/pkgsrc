$NetBSD: patch-md5.c,v 1.1 2017/07/09 16:16:32 schmonz Exp $

Support PKGSRC_USE_SSP.

--- md5.c.orig	2015-04-30 00:53:36.000000000 +0000
+++ md5.c
@@ -165,7 +165,7 @@ unsigned char *md5(unsigned char destina
   if (pad_len <= 0)
     pad_len += 64;
 
-  memcpy(padding, PAD_BLOCK, pad_len);
+  memcpy(padding, (PAD_BLOCK), pad_len);
 
   /*
    * Step 2, RFC 1321, page 3.
