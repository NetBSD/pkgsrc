$NetBSD: patch-lib_dns_rbt.c,v 1.4 2016/05/11 11:26:30 taca Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2014-09-16 19:27:15.000000000 +0000
+++ lib/dns/rbt.c
@@ -345,6 +345,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 /* The passed node must not be NULL. */
 static inline dns_rbtnode_t *
 get_subtree_root(dns_rbtnode_t *node) {
