$NetBSD: patch-modules_pike_ip__tree.c,v 1.1 2015/02/19 22:27:15 joerg Exp $

--- modules/pike/ip_tree.c.orig	2015-02-19 18:45:06.000000000 +0000
+++ modules/pike/ip_tree.c
@@ -105,7 +105,9 @@ int init_ip_tree(int maximum_hits)
 
 	for(i=0;i<MAX_IP_BRANCHES;i++) {
 		root->entries[i].node = 0;
+#if defined(FAST_LOCK) || defined(USE_PTHREAD_MUTEX) || defined(USE_POSIX_SEM)
 		root->entries[i].lock = &(root->entry_lock_set->locks[i]);
+#endif
 	}
 
 	root->max_hits = maximum_hits;
