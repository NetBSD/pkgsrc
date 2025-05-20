$NetBSD: patch-actions.c,v 1.4 2025/05/20 07:59:20 wiz Exp $

Initialize variable, fixes problem updating core packages on NetBSD.

--- actions.c.orig	2025-05-20 06:41:24.657109454 +0000
+++ actions.c
@@ -576,6 +576,7 @@ get_core_pkgs(void)
 	};
 	size_t n, p;
 	char **corepkgs = NULL;
+	n = 0;
 
 	for (p = 0; pkgs[p] != NULL; p++) {
 		if (find_local_pkg(pkgs[p], NULL) != NULL) {
