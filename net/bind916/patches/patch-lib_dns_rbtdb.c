$NetBSD: patch-lib_dns_rbtdb.c,v 1.2 2022/04/21 14:14:46 taca Exp $

* Take from NetBSD base.

--- lib/dns/rbtdb.c.orig	2022-04-11 15:28:12.000000000 +0000
+++ lib/dns/rbtdb.c
@@ -2277,7 +2277,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	NODE_UNLOCK(&rbtdb->node_locks[locknum].lock, isc_rwlocktype_write);
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static void
