$NetBSD: patch-cli_bomtool_main.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- cli/bomtool/main.c.orig	2023-01-20 21:03:49.000000000 +0000
+++ cli/bomtool/main.c
@@ -309,7 +309,7 @@ main(int argc, char *argv[])
 		if (maximum_package_count > 0 && pkgq.length > maximum_package_count)
 			break;
 
-		while (isspace((unsigned int)package[0]))
+		while (isspace((unsigned char)package[0]))
 			package++;
 
 		/* skip empty packages */
