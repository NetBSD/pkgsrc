$NetBSD: patch-lib_dns_rbt.c,v 1.4.2.1 2016/07/20 02:55:36 spz Exp $

* Disable inline on powerpc.

--- lib/dns/rbt.c.orig	2016-07-13 23:58:03.000000000 +0000
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
