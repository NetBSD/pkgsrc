$NetBSD: patch-src_common_unmime.c,v 1.1 2019/11/26 19:13:25 nia Exp $

--- src/common/unmime.c.orig	2018-11-17 13:11:44.000000000 +0000
+++ src/common/unmime.c
@@ -143,7 +143,7 @@ gchar *unmime_header(const gchar *encode
 		}
 
 		/* convert to UTF-8 */
-		conv_str = conv_codeset_strdup(decoded_text, charset, NULL);
+		conv_str = conv_codeset_strdup(decoded_text, charset, "utf-8");
 		if (!conv_str || !g_utf8_validate(conv_str, -1, NULL)) {
 			g_free(conv_str);
 			conv_str = g_malloc(len + 1);
