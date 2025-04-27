$NetBSD: patch-src_main.c,v 1.1 2025/04/27 17:46:01 thorpej Exp $

Use ctype(3) functions safely.

--- src/main.c.orig	2025-04-27 16:30:35
+++ src/main.c	2025-04-27 16:30:47
@@ -1071,7 +1071,7 @@ int get_config_value(const char *buffer, const char *n
 		val = num;
 		cur += 2; /* Advances the pointer to the first numeric character */
 		while (cur < eol) {
-			if (isxdigit((int)*cur++)) /* check for hex digit */
+			if (isxdigit((unsigned char)*cur++)) /* check for hex digit */
 			{
 				*val++ = *(cur - 1); /* put it in the buffer */
 			}
