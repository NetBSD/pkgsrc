$NetBSD: patch-lib_dns_rbt.c,v 1.3 2016/05/02 13:27:57 taca Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2016-04-20 20:11:20.000000000 +0000
+++ lib/dns/rbt.c
@@ -348,6 +348,10 @@ hexdump(const char *desc, unsigned char 
 }
 #endif /* DEBUG */
 
+#if !defined(inline) && defined(__powerpc__)
+#define        inline  /**/
+#endif
+
 #ifdef DNS_RBT_USEHASH
 
 /*
