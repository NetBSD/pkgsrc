$NetBSD: patch-lib_dns_rbtdb.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/rbtdb.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/rbtdb.c
@@ -2148,7 +2148,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	NODE_UNLOCK(&rbtdb->node_locks[locknum].lock, isc_rwlocktype_write);
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static inline void
