$NetBSD: patch-lib_dns_sdlz.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/sdlz.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/sdlz.c
@@ -451,11 +451,14 @@ closeversion(dns_db_t *db, dns_dbversion
 static isc_result_t
 createnode(dns_sdlz_db_t *sdlz, dns_sdlznode_t **nodep) {
 	dns_sdlznode_t *node;
+	void *sdlzv, *tdlzv;
 
 	node = isc_mem_get(sdlz->common.mctx, sizeof(dns_sdlznode_t));
 
 	node->sdlz = NULL;
-	attach((dns_db_t *)sdlz, (dns_db_t **)&node->sdlz);
+	sdlzv = sdlz;
+	tdlzv = &node->sdlz;
+	attach(sdlzv, tdlzv);
 	ISC_LIST_INIT(node->lists);
 	ISC_LIST_INIT(node->buffers);
 	ISC_LINK_INIT(node, link);
