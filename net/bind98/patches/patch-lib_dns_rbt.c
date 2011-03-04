$NetBSD: patch-lib_dns_rbt.c,v 1.1.1.1 2011/03/04 03:52:15 taca Exp $

--- lib/dns/rbt.c.orig	2009-10-27 04:46:58.000000000 +0000
+++ lib/dns/rbt.c
@@ -177,6 +177,10 @@ Name(dns_rbtnode_t *node) {
 static void dns_rbt_printnodename(dns_rbtnode_t *node);
 #endif
 
+#if !defined(inline) && defined(__powerpc__)
+#define	inline	/**/
+#endif
+
 static inline dns_rbtnode_t *
 find_up(dns_rbtnode_t *node) {
 	dns_rbtnode_t *root;
