$NetBSD: patch-airscan-netif.c,v 1.1 2020/12/09 12:05:58 ryoon Exp $

* Support NetBSD.

--- airscan-netif.c.orig	2020-11-23 19:47:02.000000000 +0000
+++ airscan-netif.c
@@ -578,9 +578,14 @@ netif_init (void)
         return SANE_STATUS_IO_ERROR;
     }
 
+#if defined(__NetBSD__)
+    unsigned char rtfilter[] = { RTM_NEWADDR, RTM_DELADDR };
+    if (setsockopt(netif_rtnetlink_sock, AF_ROUTE, RO_MSGFILTER,
+#else
     unsigned int rtfilter =
         ROUTE_FILTER(RTM_NEWADDR) | ROUTE_FILTER(RTM_DELADDR);
     if (setsockopt(netif_rtnetlink_sock, AF_ROUTE, ROUTE_MSGFILTER,
+#endif
                    &rtfilter, sizeof(rtfilter)) < 0) {
         log_debug(NULL, "can't set ROUTE_MSGFILTER: %s", strerror(errno));
         return SANE_STATUS_IO_ERROR;
