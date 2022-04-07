$NetBSD: patch-boilerplate_cairo-boilerplate.c,v 1.2 2022/04/07 10:57:57 riastradh Exp $

Fix ctype(3) abuse.
https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/309

--- boilerplate/cairo-boilerplate.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ boilerplate/cairo-boilerplate.c
@@ -566,7 +566,7 @@ _cairo_boilerplate_target_matches_name (
     if (! (name_len == 1 && 0 == strncmp (tname, "?", 1))) { /* wildcard? */
 	if (0 != strncmp (target->name, tname, name_len)) /* exact match? */
 	    return FALSE;
-	if (isalnum (target->name[name_len]))
+	if (isalnum ((unsigned char)target->name[name_len]))
 	    return FALSE;
     }
 
