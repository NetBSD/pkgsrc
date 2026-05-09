$NetBSD: patch-example_cuse__client.c,v 1.1 2026/05/09 20:00:28 vins Exp $

Fix ctype warning.

--- example/cuse_client.c.orig	2026-05-06 16:55:14.227070883 +0000
+++ example/cuse_client.c
@@ -106,7 +106,7 @@ int main(int argc, char **argv)
 		return 1;
 	}
 
-	cmd = tolower(argv[2][0]);
+	cmd = tolower((unsigned char)argv[2][0]);
 	argc -= 3;
 	argv += 3;
 
