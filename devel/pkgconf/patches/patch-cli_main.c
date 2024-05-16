$NetBSD: patch-cli_main.c,v 1.3 2024/05/16 21:31:47 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/pull/358

--- cli/main.c.orig	2024-03-27 18:36:26.000000000 +0000
+++ cli/main.c
@@ -369,7 +369,7 @@ apply_modversion(pkgconf_client_t *clien
 			if (name_len > strlen(queue_node->package) ||
 			    strncmp(pkg->why, queue_node->package, name_len) ||
 			    (queue_node->package[name_len] != 0 &&
-			     !isspace(queue_node->package[name_len]) &&
+			     !isspace((unsigned char)queue_node->package[name_len]) &&
 			     !PKGCONF_IS_OPERATOR_CHAR(queue_node->package[name_len])))
 				continue;
 
