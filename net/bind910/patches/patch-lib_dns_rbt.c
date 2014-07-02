$NetBSD: patch-lib_dns_rbt.c,v 1.1.1.1 2014/07/02 02:42:58 jnemeth Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2014-05-27 04:45:53.000000000 +0000
+++ lib/dns/rbt.c
@@ -328,6 +328,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 static inline dns_rbtnode_t *
 find_up(dns_rbtnode_t *node) {
 	dns_rbtnode_t *root;
