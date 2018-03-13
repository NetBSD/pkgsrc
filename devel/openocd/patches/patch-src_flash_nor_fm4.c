$NetBSD: patch-src_flash_nor_fm4.c,v 1.1 2018/03/13 03:01:15 dholland Exp $

Fix ctype.h misuse.

--- src/flash/nor/fm4.c~	2016-12-25 14:12:54.000000000 +0000
+++ src/flash/nor/fm4.c
@@ -609,7 +609,7 @@ static bool fm4_name_match(const char *s
 		if (!pattern[i])
 			return true;
 		/* Use x as wildcard */
-		if (pattern[i] != 'x' && tolower(s[i]) != tolower(pattern[i]))
+		if (pattern[i] != 'x' && tolower((unsigned char)s[i]) != tolower((unsigned char)pattern[i]))
 			return false;
 		i++;
 	}
