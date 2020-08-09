$NetBSD: patch-lib_dns_peer.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/peer.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/peer.c
@@ -214,6 +214,8 @@ dns_peer_newprefix(isc_mem_t *mem, const
 
 	peer = isc_mem_get(mem, sizeof(*peer));
 
+#ifndef __lint__
+// XXX: bug
 	*peer = (dns_peer_t){
 		.magic = DNS_PEER_MAGIC,
 		.address = *addr,
@@ -221,6 +223,7 @@ dns_peer_newprefix(isc_mem_t *mem, const
 		.mem = mem,
 		.transfer_format = dns_one_answer,
 	};
+#endif
 
 	isc_refcount_init(&peer->refs, 1);
 
