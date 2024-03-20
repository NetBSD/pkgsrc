$NetBSD: patch-lib_dns_rbtdb.c,v 1.3 2024/03/20 14:59:15 taca Exp $

* Take from NetBSD base.

--- lib/dns/rbtdb.c.orig	2024-03-12 08:51:08.618355570 +0000
+++ lib/dns/rbtdb.c
@@ -2222,7 +2222,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	NODE_UNLOCK(&rbtdb->node_locks[locknum].lock, isc_rwlocktype_write);
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static void
