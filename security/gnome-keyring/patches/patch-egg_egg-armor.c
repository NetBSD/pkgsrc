$NetBSD: patch-egg_egg-armor.c,v 1.1 2020/11/22 21:26:51 nia Exp $

Argument to ctype functions must be unsigned char.

--- egg/egg-armor.c.orig	2019-02-09 17:20:04.000000000 +0000
+++ egg/egg-armor.c
@@ -188,7 +188,7 @@ armor_find_end (const gchar *data,
 
 	if (outer != NULL) {
 		at += ARMOR_SUFF_L;
-		if (isspace (at[0]))
+		if (isspace ((unsigned char)at[0]))
 			at++;
 		*outer = at;
 	}
@@ -226,7 +226,7 @@ armor_parse_block (const gchar *data,
 		if (!x)
 			break;
 		++x;
-		while (isspace (*x)) {
+		while (isspace ((unsigned char)*x)) {
 			/* Found a second line, with only spaces between */
 			if (*x == '\n') {
 				hbeg = data;
