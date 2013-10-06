$NetBSD: patch-plugins_symbol-db_anjuta-tags_eiffel.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/eiffel.c.orig	2013-09-29 15:17:26.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/eiffel.c
@@ -807,7 +807,7 @@ static void findKeyword (tokenInfo *cons
 
 static boolean parseType (tokenInfo *const token);
 
-static void parseGeneric (tokenInfo *const token, boolean declaration __unused__)
+static void parseGeneric (tokenInfo *const token, boolean declaration )
 {
 	unsigned int depth = 0;
 #ifdef TYPE_REFERENCE_TOOL
