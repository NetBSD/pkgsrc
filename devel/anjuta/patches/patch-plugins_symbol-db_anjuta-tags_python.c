$NetBSD: patch-plugins_symbol-db_anjuta-tags_python.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/python.c.orig	2013-09-29 15:17:40.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/python.c
@@ -135,7 +135,7 @@ static boolean isIdentifierCharacter (in
  * extract all relevant information and create a tag.
  */
 static void makeFunctionTag (vString *const function,
-	vString *const parent, int is_class_parent, const char *arglist __unused__)
+	vString *const parent, int is_class_parent, const char *arglist )
 {
 	tagEntryInfo tag;
 	initTagEntry (&tag, vStringValue (function));
