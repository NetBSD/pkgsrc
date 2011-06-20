$NetBSD: patch-ext_standard_crypt__blowfish.c,v 1.1 2011/06/20 13:38:19 taca Exp $

- Fix potential security problem by char signedness processing:
  http://www.openwall.com/lists/oss-security/2011/06/20/2

--- ext/standard/crypt_blowfish.c.orig	2010-02-21 23:47:14.000000000 +0000
+++ ext/standard/crypt_blowfish.c
@@ -565,7 +565,7 @@ static void BF_set_key(__CONST char *key
 		tmp = 0;
 		for (j = 0; j < 4; j++) {
 			tmp <<= 8;
-			tmp |= *ptr;
+			tmp |= (unsigned char)*ptr;
 
 			if (!*ptr) ptr = key; else ptr++;
 		}
