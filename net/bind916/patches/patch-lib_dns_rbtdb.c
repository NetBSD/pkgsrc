$NetBSD: patch-lib_dns_rbtdb.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/rbtdb.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/rbtdb.c
@@ -2218,7 +2218,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	NODE_UNLOCK(&rbtdb->node_locks[locknum].lock, isc_rwlocktype_write);
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static inline void
