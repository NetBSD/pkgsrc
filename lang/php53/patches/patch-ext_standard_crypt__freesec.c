$NetBSD: patch-ext_standard_crypt__freesec.c,v 1.1 2012/05/31 15:58:10 taca Exp $

Fix for CVE_2012-2143.

--- ext/standard/crypt_freesec.c.orig	2012-05-08 09:22:27.000000000 +0000
+++ ext/standard/crypt_freesec.c
@@ -629,7 +629,8 @@ _crypt_extended_r(const char *key, const
 	 */
 	q = (u_char *) keybuf;
 	while (q - (u_char *) keybuf < sizeof(keybuf)) {
-		if ((*q++ = *key << 1))
+		*q++ = *key << 1;
+		if (*key)
 			key++;
 	}
 	if (des_setkey((u_char *) keybuf, data))
