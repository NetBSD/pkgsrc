$NetBSD: patch-lib_isc_netmgr_netmgr.c,v 1.3 2024/02/13 15:25:33 taca Exp $

* Take from NetBSD base.

--- lib/isc/netmgr/netmgr.c.orig	2024-02-11 11:31:39.000000000 +0000
+++ lib/isc/netmgr/netmgr.c
@@ -358,7 +358,7 @@ isc__netmgr_create(isc_mem_t *mctx, uint
 		mgr->workers_running++;
 		isc_thread_create(nm_thread, &mgr->workers[i], &worker->thread);
 
-		snprintf(name, sizeof(name), "isc-net-%04d", i);
+		snprintf(name, sizeof(name), "net-%04d", i);
 		isc_thread_setname(worker->thread, name);
 	}
 
@@ -1794,6 +1794,13 @@ isc_nmhandle_getdata(isc_nmhandle_t *han
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
