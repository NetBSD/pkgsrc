$NetBSD: patch-lib_dns_keytable.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/keytable.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/keytable.c
@@ -356,7 +356,7 @@ dns_keytable_deletekeynode(dns_keytable_
 		goto finish;
 	}
 
-	kprev = (dns_keynode_t **) &node->data;
+	kprev = (dns_keynode_t **)(void *)&node->data;
 	while (knode != NULL) {
 		if (knode->key != NULL &&
 		    dst_key_compare(knode->key, dstkey) == true)
