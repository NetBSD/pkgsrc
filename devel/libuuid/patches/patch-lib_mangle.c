$NetBSD: patch-lib_mangle.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- lib/mangle.c.orig	2018-06-04 07:57:02.793445882 +0000
+++ lib/mangle.c
@@ -80,9 +80,11 @@ size_t unhexmangle_to_buffer(const char 
 
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
