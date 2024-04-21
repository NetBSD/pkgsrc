$NetBSD: patch-main.c,v 1.2 2024/04/21 20:37:52 thorpej Exp $

Use ctype(3) functions safely.

--- main.c.orig	2024-04-21 20:31:05.892824868 +0000
+++ main.c	2024-04-21 20:31:14.668888370 +0000
@@ -987,7 +987,7 @@ int get_config_value(const char *buffer,
 		val = num;
 		cur += 2; /* Advances the pointer to the first numeric character */
 		while (cur < eol) {
-			if (isxdigit((int)*cur++)) /* check for hex digit */
+			if (isxdigit((unsigned char)*cur++)) /* check for hex digit */
 			{
 				*val++ = *(cur - 1); /* put it in the buffer */
 			}
