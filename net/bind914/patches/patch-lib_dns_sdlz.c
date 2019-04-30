$NetBSD: patch-lib_dns_sdlz.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/sdlz.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/sdlz.c
@@ -467,13 +467,16 @@ closeversion(dns_db_t *db, dns_dbversion
 static isc_result_t
 createnode(dns_sdlz_db_t *sdlz, dns_sdlznode_t **nodep) {
 	dns_sdlznode_t *node;
+	void *sdlzv, *tdlzv;
 
 	node = isc_mem_get(sdlz->common.mctx, sizeof(dns_sdlznode_t));
 	if (node == NULL)
 		return (ISC_R_NOMEMORY);
 
 	node->sdlz = NULL;
-	attach((dns_db_t *)sdlz, (dns_db_t **)&node->sdlz);
+	sdlzv = sdlz;
+	tdlzv = &node->sdlz;
+	attach(sdlzv, tdlzv);
 	ISC_LIST_INIT(node->lists);
 	ISC_LIST_INIT(node->buffers);
 	ISC_LINK_INIT(node, link);
