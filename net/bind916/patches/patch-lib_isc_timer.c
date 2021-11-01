$NetBSD: patch-lib_isc_timer.c,v 1.1.2.2 2021/11/01 22:24:56 tm Exp $

* Take from NetBSD base.

--- lib/isc/timer.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/isc/timer.c
@@ -696,7 +696,7 @@ isc_timermgr_create(isc_mem_t *mctx, isc
 	isc_mem_attach(mctx, &manager->mctx);
 	isc_condition_init(&manager->wakeup);
 	isc_thread_create(run, manager, &manager->thread);
-	isc_thread_setname(manager->thread, "isc-timer");
+	isc_thread_setname(manager->thread, "timer");
 
 	*managerp = manager;
 
