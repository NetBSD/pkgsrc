$NetBSD: patch-lib_isc_hp.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/hp.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/hp.c
@@ -82,7 +82,7 @@ struct isc_hp {
 };
 
 static inline int
-tid() {
+tid(void) {
 	if (tid_v == TID_UNKNOWN) {
 		tid_v = atomic_fetch_add(&tid_v_base, 1);
 		REQUIRE(tid_v < isc__hp_max_threads);
