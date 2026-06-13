$NetBSD: patch-src_util.c,v 1.1 2026/06/13 11:06:10 markd Exp $

error: array subscript has type 'char'

--- src/util.c.orig	2026-06-03 16:26:36.000000000 +0000
+++ src/util.c
@@ -412,10 +412,10 @@ static char *_oauth2_trim(char *src)
 	buf = oauth2_strdup(src);
 	start = buf;
 
-	while (isspace(*start))
+	while (isspace((unsigned char)*start))
 		++start;
 	end = &start[strlen(start)];
-	while (--end >= start && isspace(*end))
+	while (--end >= start && isspace((unsigned char)*end))
 		*end = '\0';
 
 	rv = oauth2_strdup(start);
