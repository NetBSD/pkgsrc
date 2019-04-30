$NetBSD: patch-bin_named_pfilter.h,v 1.1 2019/04/30 03:34:34 taca Exp $

* Add support for blacklistd.

--- bin/named/pfilter.h.orig	2019-04-29 06:38:25.989360716 +0000
+++ bin/named/pfilter.h
@@ -0,0 +1,2 @@
+void pfilter_open(void);
+void pfilter_notify(isc_result_t, ns_client_t *, const char *);
