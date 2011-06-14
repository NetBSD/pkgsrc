$NetBSD: patch-aux.c,v 1.1 2011/06/14 13:13:31 wiz Exp $

--- aux.c.orig	2005-07-21 22:03:00.000000000 +0000
+++ aux.c
@@ -507,7 +507,7 @@ aux_sh(article_header * ah, char *script
 		prompt_line = Lines - 1;
 		prompt("To: ");
 		unset_raw();
-		if (getline(&cc[0], sizeof(cc)) == 0)
+		if (nngetline(&cc[0], sizeof(cc)) == 0)
 		    cc[0] = CR;
 		nn_raw();
 		if (cc[0] != CR)
