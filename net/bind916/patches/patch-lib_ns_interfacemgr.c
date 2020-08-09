$NetBSD: patch-lib_ns_interfacemgr.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/ns/interfacemgr.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/ns/interfacemgr.c
@@ -396,9 +396,12 @@ ns_interface_create(ns_interfacemgr_t *m
 	REQUIRE(NS_INTERFACEMGR_VALID(mgr));
 
 	ifp = isc_mem_get(mgr->mctx, sizeof(*ifp));
+#ifndef __lint__
+/* XXX: bug? */
 	*ifp = (ns_interface_t){ .generation = mgr->generation,
 				 .addr = *addr,
 				 .dscp = -1 };
+#endif
 
 	strlcpy(ifp->name, name, sizeof(ifp->name));
 
