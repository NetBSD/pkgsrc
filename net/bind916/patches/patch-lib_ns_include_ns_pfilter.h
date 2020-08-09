$NetBSD: patch-lib_ns_include_ns_pfilter.h,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/ns/include/ns/pfilter.h.orig	2020-05-27 15:17:34.854399492 +0000
+++ lib/ns/include/ns/pfilter.h
@@ -0,0 +1,2 @@
+void pfilter_enable(void);
+void pfilter_notify(isc_result_t, ns_client_t *, const char *);
