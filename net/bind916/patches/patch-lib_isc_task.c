$NetBSD: patch-lib_isc_task.c,v 1.2 2021/06/02 15:37:06 taca Exp $

* Take from NetBSD base.

--- lib/isc/task.c.orig	2021-05-12 09:53:16.000000000 +0000
+++ lib/isc/task.c
@@ -1412,7 +1412,7 @@ isc_taskmgr_create(isc_mem_t *mctx, unsi
 		isc_thread_create(run, &manager->queues[i],
 				  &manager->queues[i].thread);
 		char name[21];
-		snprintf(name, sizeof(name), "isc-worker%04u", i);
+		snprintf(name, sizeof(name), "work-%u", i);
 		isc_thread_setname(manager->queues[i].thread, name);
 	}
 	UNLOCK(&manager->lock);
