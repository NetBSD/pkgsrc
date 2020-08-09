$NetBSD: patch-lib_isc_include_isc_netmgr.h,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/include/isc/netmgr.h.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/include/isc/netmgr.h
@@ -96,6 +96,9 @@ isc_nmhandle_unref(isc_nmhandle_t *handl
  * with the client.)
  */
 
+int
+isc_nmhandle_getfd(isc_nmhandle_t *handle);
+
 void *
 isc_nmhandle_getdata(isc_nmhandle_t *handle);
 
