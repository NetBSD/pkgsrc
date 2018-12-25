$NetBSD: patch-md5.c,v 1.2 2018/12/25 16:24:26 schmonz Exp $

Support PKGSRC_USE_SSP.

--- md5.c.orig	2015-04-30 00:53:36.000000000 +0000
+++ md5.c
@@ -128,7 +128,7 @@ unsigned char *htole(unsigned char *dest
  * Return value:
  *   X circular left-shifted n positions
  */
-inline uint32_t lshift(uint32_t X, int n)
+static inline uint32_t lshift(uint32_t X, int n)
   {
   return((n > 0) ? ((X << n) | (X >> (32 - n))) : X);
   }
@@ -165,7 +165,7 @@ unsigned char *md5(unsigned char destina
   if (pad_len <= 0)
     pad_len += 64;
 
-  memcpy(padding, PAD_BLOCK, pad_len);
+  memcpy(padding, (PAD_BLOCK), pad_len);
 
   /*
    * Step 2, RFC 1321, page 3.
