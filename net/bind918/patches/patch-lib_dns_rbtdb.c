$NetBSD: patch-lib_dns_rbtdb.c,v 1.2 2024/02/13 13:50:39 taca Exp $

* Take from NetBSD base.

--- lib/dns/rbtdb.c.orig	2024-02-11 10:42:55.656990155 +0000
+++ lib/dns/rbtdb.c
@@ -2234,7 +2234,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	}
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static void
