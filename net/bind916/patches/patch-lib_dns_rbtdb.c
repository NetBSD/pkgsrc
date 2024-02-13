$NetBSD: patch-lib_dns_rbtdb.c,v 1.3 2024/02/13 15:25:33 taca Exp $

* Take from NetBSD base.

--- lib/dns/rbtdb.c.orig	2024-02-11 11:31:39.000000000 +0000
+++ lib/dns/rbtdb.c
@@ -2327,7 +2327,7 @@ prune_tree(isc_task_t *task, isc_event_t
 	}
 	RWUNLOCK(&rbtdb->tree_lock, isc_rwlocktype_write);
 
-	detach((dns_db_t **)&rbtdb);
+	detach((dns_db_t **)(void *)&rbtdb);
 }
 
 static void
