$NetBSD: patch-pkgsrc.c,v 1.2 2017/12/29 11:59:13 plunky Exp $

Fix const correctness.

--- pkgsrc.c.orig	2009-03-08 14:25:53.000000000 +0000
+++ pkgsrc.c
@@ -80,7 +80,7 @@ list_mirrors(const char *method)
 
 	if ((list = build_mirror_list(method)) == NULL)
 		return(NULL);
-	if ((etree = build_tree_from_list((const char **)list)) == NULL) {
+	if ((etree = build_tree_from_list((const char *const *)list)) == NULL) {
 		free_list(&list);
 		return(NULL);
 	}
@@ -247,7 +247,7 @@ get_cvs_branch(const char *anoncvs, int 
 	free_list(&list);
 	
 	if ((etree = 
-	     build_tree_from_list((const char **)branchlist)) == NULL) {
+	     build_tree_from_list((const char *const *)branchlist)) == NULL) {
 		free_list(&branchlist);
 		return(NULL);
 	}
