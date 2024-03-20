$NetBSD: patch-lib_dns_rbtdb.c,v 1.4 2024/03/20 14:57:54 taca Exp $

* Take from NetBSD base.

--- lib/dns/rbtdb.c.orig	2024-03-12 08:43:03.000000000 +0000
+++ lib/dns/rbtdb.c
@@ -2312,7 +2312,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	NODE_UNLOCK(&rbtdb->node_locks[locknum].lock, isc_rwlocktype_write);
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static void
