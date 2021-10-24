$NetBSD: patch-lib_isc_netmgr_netmgr.c,v 1.2 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/isc/netmgr/netmgr.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/isc/netmgr/netmgr.c
@@ -373,7 +373,7 @@ isc__netmgr_create(isc_mem_t *mctx, uint
 		mgr->workers_running++;
 		isc_thread_create(nm_thread, &mgr->workers[i], &worker->thread);
 
-		snprintf(name, sizeof(name), "isc-net-%04zu", i);
+		snprintf(name, sizeof(name), "net-%04zu", i);
 		isc_thread_setname(worker->thread, name);
 	}
 
@@ -1828,6 +1828,13 @@ isc_nmhandle_getdata(isc_nmhandle_t *han
 	return (handle->opaque);
 }
 
+int
+isc_nmhandle_getfd(isc_nmhandle_t *handle) {
+	REQUIRE(VALID_NMHANDLE(handle));
+
+	return (handle->sock->fd);
+}
+
 void
 isc_nmhandle_setdata(isc_nmhandle_t *handle, void *arg,
 		     isc_nm_opaquecb_t doreset, isc_nm_opaquecb_t dofree) {
