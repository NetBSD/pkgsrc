$NetBSD: patch-plugins_symbol-db_anjuta-tags_routines.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/routines.c.orig	2013-09-29 15:17:42.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/routines.c
@@ -526,7 +526,7 @@ static boolean isPathSeparator (const in
 
 #if ! defined (HAVE_STAT_ST_INO)
 
-static void canonicalizePath (char *const path __unused__)
+static void canonicalizePath (char *const path)
 {
 #if defined (MSDOS_STYLE_PATH)
 	char *p;
