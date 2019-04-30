$NetBSD: patch-lib_dns_sdb.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/sdb.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/sdb.c
@@ -658,7 +658,7 @@ createnode(dns_sdb_t *sdb, dns_sdbnode_t
 		return (ISC_R_NOMEMORY);
 
 	node->sdb = NULL;
-	attach((dns_db_t *)sdb, (dns_db_t **)&node->sdb);
+	attach((dns_db_t *)sdb, (dns_db_t **)(void *)&node->sdb);
 	ISC_LIST_INIT(node->lists);
 	ISC_LIST_INIT(node->buffers);
 	ISC_LINK_INIT(node, link);
