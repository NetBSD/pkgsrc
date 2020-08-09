$NetBSD: patch-lib_dns_sdb.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/sdb.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/sdb.c
@@ -621,7 +621,7 @@ createnode(dns_sdb_t *sdb, dns_sdbnode_t
 	node = isc_mem_get(sdb->common.mctx, sizeof(dns_sdbnode_t));
 
 	node->sdb = NULL;
-	attach((dns_db_t *)sdb, (dns_db_t **)&node->sdb);
+	attach((dns_db_t *)sdb, (dns_db_t **)(void *)&node->sdb);
 	ISC_LIST_INIT(node->lists);
 	ISC_LIST_INIT(node->buffers);
 	ISC_LINK_INIT(node, link);
