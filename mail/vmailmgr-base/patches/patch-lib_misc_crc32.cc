$NetBSD: patch-lib_misc_crc32.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Remove unsupported keyword.

--- lib/misc/crc32.cc.orig	2024-02-22 18:31:14.384171118 +0000
+++ lib/misc/crc32.cc
@@ -132,7 +132,7 @@ const crc32_t crc32tab[] = { /* a table
 crc32_t crc32_c::update (const unsigned char *s, int len)
 /* update running CRC calculation with contents of a buffer */
 {
-	register crc32_t a = val;
+	crc32_t a = val;
 	while(len-- > 0)
 		a = crc32_update (a, *s++);
 	return (val = a) ^ CRC32INIT;
