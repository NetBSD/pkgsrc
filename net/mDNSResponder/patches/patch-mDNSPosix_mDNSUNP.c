$NetBSD: patch-mDNSPosix_mDNSUNP.c,v 1.1 2024/11/20 17:56:21 hauke Exp $

* For OpenBSD, from
  http://lists.apple.com/archives/bonjour-dev/2007/Jan/msg00003.html

--- mDNSPosix/mDNSUNP.c.orig	2024-11-20 16:16:30.408955628 +0000
+++ mDNSPosix/mDNSUNP.c
@@ -87,6 +87,14 @@ recvfrom_flags(int fd, void *ptr, size_t
            set the value to 0, but I'm concerned that 0
            might be a valid interface value.
          */
+#if HAVE_BROKEN_RECVDSTADDR
+        /* similar to the issue with OpenBSD in mDNSPosix.c, we need
+           to preset sin_family to IF_NET, because of broken IP_RECVDSTADDR
+         */
+        struct in_pktinfo *tmp;
+        struct sockaddr_in *sin = (struct sockaddr_in*)&pktp->ipi_addr;
+        sin->sin_family = AF_INET;
+#endif
         memset(pktp, 0, sizeof(struct my_in_pktinfo));
         pktp->ipi_ifindex = -1;
     }
