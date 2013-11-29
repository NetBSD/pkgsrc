$NetBSD: patch-listmgt.c,v 1.1 2013/11/29 23:13:56 dholland Exp $

Fix const correctness.

--- listmgt.c~	2009-03-08 14:25:53.000000000 +0000
+++ listmgt.c
@@ -90,7 +90,7 @@ entry_search(Etree **etree, int cont)
 }
 
 Etree **
-build_tree_from_list(const char **list)
+build_tree_from_list(const char *const *list)
 {
 	int i, count, len;
 	char *p;
