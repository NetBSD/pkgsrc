$NetBSD: patch-plugins_symbol-db_anjuta-tags_lua.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/lua.c.orig	2013-09-29 15:17:31.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/lua.c
@@ -37,7 +37,7 @@ static kindOption LuaKinds [] = {
 */
 
 /* for debugging purposes */
-static void __unused__ print_string (char *p, char *q)
+static void print_string (char *p, char *q)
 {
 	for ( ; p != q; p++)
 		fprintf (errout, "%c", *p);
