$NetBSD: patch-lib_isc_include_isc_netmgr.h,v 1.3 2021/03/21 04:16:17 taca Exp $

Declare missing prototype.

--- lib/isc/include/isc/netmgr.h.orig	2021-03-11 13:20:59.000000000 +0000
+++ lib/isc/include/isc/netmgr.h
@@ -146,6 +146,9 @@ isc_nmhandle_getdata(isc_nmhandle_t *han
 void *
 isc_nmhandle_getextra(isc_nmhandle_t *handle);
 
+int
+isc_nmhandle_getfd(isc_nmhandle_t *handle);
+
 bool
 isc_nmhandle_is_stream(isc_nmhandle_t *handle);
 
