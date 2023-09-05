$NetBSD: patch-airscan-netif.c,v 1.2 2023/09/05 14:42:18 ryoon Exp $

* Support NetBSD.

--- airscan-netif.c.orig	2021-10-04 18:36:05.000000000 +0000
+++ airscan-netif.c
@@ -589,9 +589,14 @@ netif_init (void)
     }
 
 #ifdef ROUTE_MSGFILTER
+#if defined(__NetBSD__)
+    unsigned char rtfilter[] = { RTM_NEWADDR, RTM_DELADDR };
+    if (setsockopt(netif_rtnetlink_sock, AF_ROUTE, RO_MSGFILTER,
+#else
     unsigned int rtfilter =
         ROUTE_FILTER(RTM_NEWADDR) | ROUTE_FILTER(RTM_DELADDR);
     if (setsockopt(netif_rtnetlink_sock, AF_ROUTE, ROUTE_MSGFILTER,
+#endif
                    &rtfilter, sizeof(rtfilter)) < 0) {
         /* Note, this error is not fatal for us, it is enough to
          * log it and continue
