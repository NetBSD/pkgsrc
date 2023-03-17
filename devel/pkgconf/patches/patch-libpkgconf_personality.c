$NetBSD: patch-libpkgconf_personality.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/personality.c.orig	2022-06-26 03:11:36.000000000 +0000
+++ libpkgconf/personality.c
@@ -141,7 +141,7 @@ valid_triplet(const char *triplet)
 	const char *c = triplet;
 
 	for (; *c; c++)
-		if (!isalnum(*c) && *c != '-' && *c != '_')
+		if (!isalnum((unsigned char)*c) && *c != '-' && *c != '_')
 			return false;
 
 	return true;
