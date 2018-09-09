$NetBSD: patch-lib_dns_rbt.c,v 1.1 2018/09/09 13:16:01 taca Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2018-07-03 06:56:55.000000000 +0000
+++ lib/dns/rbt.c
@@ -344,6 +344,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 #ifdef DNS_RBT_USEHASH
 
 /*
