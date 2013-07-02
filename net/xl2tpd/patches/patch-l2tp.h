$NetBSD: patch-l2tp.h,v 1.1 2013/07/02 00:22:17 christos Exp $

Detect if we have IP_PKTINFO

--- l2tp.h.orig	2013-06-26 13:42:03.000000000 -0400
+++ l2tp.h	2013-06-26 13:41:15.000000000 -0400
@@ -172,7 +172,9 @@
     struct call *self;
     struct lns *lns;            /* LNS that owns us */
     struct lac *lac;            /* LAC that owns us */
+#ifdef IP_PKTINFO
     struct in_pktinfo my_addr;  /* Address of my endpoint */
+#endif
 };
 
 struct tunnel_list
