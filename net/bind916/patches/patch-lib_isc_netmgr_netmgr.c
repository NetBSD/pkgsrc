$NetBSD: patch-lib_isc_netmgr_netmgr.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/netmgr/netmgr.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/netmgr/netmgr.c
@@ -1197,6 +1197,13 @@ isc_nmhandle_getdata(isc_nmhandle_t *han
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
