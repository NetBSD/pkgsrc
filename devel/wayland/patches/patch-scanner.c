$NetBSD: patch-scanner.c,v 1.1 2025/04/07 17:33:30 prlw1 Exp $

Avoid segmentation fault when building wayland-protocols

--- src/scanner.c.orig	2024-05-30 18:59:51.000000000 +0000
+++ src/scanner.c
@@ -294,7 +294,7 @@ uppercase_dup(const char *src)
 
 	u = xstrdup(src);
 	for (i = 0; u[i]; i++)
-		u[i] = toupper(u[i]);
+		u[i] = toupper((unsigned char)u[i]);
 	u[i] = '\0';
 
 	return u;
@@ -354,7 +354,7 @@ desc_dump(char *desc, const char *fmt, .
 	for (i = 0; desc[i]; ) {
 		k = i;
 		newlines = 0;
-		while (desc[i] && isspace(desc[i])) {
+		while (desc[i] && isspace((unsigned char)desc[i])) {
 			if (desc[i] == '\n')
 				newlines++;
 			i++;
@@ -363,7 +363,7 @@ desc_dump(char *desc, const char *fmt, .
 			break;
 
 		j = i;
-		while (desc[i] && !isspace(desc[i]))
+		while (desc[i] && !isspace((unsigned char)desc[i]))
 			i++;
 
 		if (newlines > 1)
