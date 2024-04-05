$NetBSD: patch-src_util_str.c,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure proper value range for arg to isxdigit().

--- src/util/str.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/util/str.c
@@ -485,8 +485,8 @@ int git_str_decode_percent(
 	for (str_pos = 0; str_pos < str_len; buf->size++, str_pos++) {
 		if (str[str_pos] == '%' &&
 			str_len > str_pos + 2 &&
-			isxdigit(str[str_pos + 1]) &&
-			isxdigit(str[str_pos + 2])) {
+			isxdigit((unsigned char)str[str_pos + 1]) &&
+			isxdigit((unsigned char)str[str_pos + 2])) {
 			buf->ptr[buf->size] = (HEX_DECODE(str[str_pos + 1]) << 4) +
 				HEX_DECODE(str[str_pos + 2]);
 			str_pos += 2;
