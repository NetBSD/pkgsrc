$NetBSD: patch-src_libjasper_jpc_jpc__tagtree.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_tagtree.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_tagtree.c
@@ -125,7 +125,7 @@ jpc_tagtree_t *jpc_tagtree_create(int nu
 		++numlvls;
 	} while (n > 1);
 
-	if (!(tree->nodes_ = jas_malloc(tree->numnodes_ * sizeof(jpc_tagtreenode_t)))) {
+	if (!(tree->nodes_ = jas_alloc2(tree->numnodes_, sizeof(jpc_tagtreenode_t)))) {
 		return 0;
 	}
 
