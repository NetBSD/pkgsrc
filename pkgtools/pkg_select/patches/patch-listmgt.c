$NetBSD: patch-listmgt.c,v 1.2 2017/12/29 11:59:13 plunky Exp $

Fix const correctness.

--- listmgt.c.orig	2009-03-08 14:25:53.000000000 +0000
+++ listmgt.c
@@ -90,7 +90,7 @@ entry_search(Etree **etree, int cont)
 }
 
 Etree **
-build_tree_from_list(const char **list)
+build_tree_from_list(const char *const *list)
 {
 	int i, count, len;
 	char *p;
