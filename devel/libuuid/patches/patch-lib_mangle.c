$NetBSD: patch-lib_mangle.c,v 1.2 2024/12/28 14:10:24 wiz Exp $

Fix ctype(3) abuse.

--- lib/mangle.c.orig	2024-01-31 10:02:15.457811585 +0000
+++ lib/mangle.c
@@ -81,9 +81,11 @@ size_t unhexmangle_to_buffer(const char 
 
 	while(*s && sz < len - 1) {
 		if (*s == '\\' && sz + 3 < len - 1 && s[1] == 'x' &&
-		    isxdigit(s[2]) && isxdigit(s[3])) {
+		    isxdigit((unsigned char)s[2]) &&
+		    isxdigit((unsigned char)s[3])) {
 
-			*buf++ = from_hex(s[2]) << 4 | from_hex(s[3]);
+			*buf++ = from_hex((unsigned char)s[2]) << 4 |
+			    from_hex((unsigned char)s[3]);
 			s += 4;
 			sz += 4;
 		} else {
