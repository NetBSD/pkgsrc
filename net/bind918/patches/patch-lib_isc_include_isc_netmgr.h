$NetBSD: patch-lib_isc_include_isc_netmgr.h,v 1.1 2022/12/11 01:57:55 sekiya Exp $

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
 
