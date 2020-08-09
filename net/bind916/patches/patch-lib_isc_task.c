$NetBSD: patch-lib_isc_task.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/task.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/task.c
@@ -1381,8 +1381,11 @@ isc_taskmgr_create(isc_mem_t *mctx, unsi
 	REQUIRE(managerp != NULL && *managerp == NULL);
 
 	manager = isc_mem_get(mctx, sizeof(*manager));
+#ifndef __lint__
+// XXX: bug
 	*manager = (isc__taskmgr_t){ .common.impmagic = TASK_MANAGER_MAGIC,
 				     .common.magic = ISCAPI_TASKMGR_MAGIC };
+#endif
 
 	atomic_store(&manager->mode, isc_taskmgrmode_normal);
 	isc_mutex_init(&manager->lock);
@@ -1431,7 +1434,7 @@ isc_taskmgr_create(isc_mem_t *mctx, unsi
 		isc_thread_create(run, &manager->queues[i],
 				  &manager->queues[i].thread);
 		char name[21];
-		snprintf(name, sizeof(name), "isc-worker%04u", i);
+		snprintf(name, sizeof(name), "work-%u", i);
 		isc_thread_setname(manager->queues[i].thread, name);
 	}
 	UNLOCK(&manager->lock);
