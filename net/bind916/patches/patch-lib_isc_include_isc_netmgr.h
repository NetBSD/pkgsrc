$NetBSD: patch-lib_isc_include_isc_netmgr.h,v 1.2 2021/01/29 16:17:15 otis Exp $

Declare missing prototype.

--- lib/isc/include/isc/netmgr.h.orig	2021-01-11 13:23:31.000000000 +0000
+++ lib/isc/include/isc/netmgr.h
@@ -510,3 +510,6 @@ isc_nm_tlsdnsconnect(isc_nm_t *mgr, isc_
 isc_result_t
 isc_nm_tls_create_server_ctx(const char *keyfile, const char *certfile,
 			     isc_ssl_ctx_t **ctxp);
+
+int
+isc_nmhandle_getfd(isc_nmhandle_t *handle);
