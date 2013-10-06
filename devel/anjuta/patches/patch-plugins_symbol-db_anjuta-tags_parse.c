$NetBSD: patch-plugins_symbol-db_anjuta-tags_parse.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/parse.c.orig	2013-09-29 15:17:37.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/parse.c
@@ -376,7 +376,7 @@ extern void freeParserResources (void)
 */
 
 extern void processLanguageDefineOption (
-		const char *const option, const char *const parameter __unused__)
+		const char *const option, const char *const parameter )
 {
 #ifdef HAVE_REGEX
 	if (parameter [0] == '\0')
