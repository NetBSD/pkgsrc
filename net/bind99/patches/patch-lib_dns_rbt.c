$NetBSD: patch-lib_dns_rbt.c,v 1.2 2016/05/02 13:22:06 taca Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2016-04-20 20:11:30.000000000 +0000
+++ lib/dns/rbt.c
@@ -179,6 +179,10 @@ Name(dns_rbtnode_t *node) {
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define	inline	/**/
+#endif
+
 #ifdef DNS_RBT_USEHASH
 
 /*
