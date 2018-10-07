$NetBSD: patch-minissdp.c,v 1.1 2018/10/07 09:12:31 adam Exp $

Fix building.

--- minissdp.c.orig	2018-10-07 09:08:52.068679678 +0000
+++ minissdp.c
@@ -873,8 +873,7 @@ ProcessSSDPRequest(int s, unsigned short
 		.msg_controllen = sizeof(cmbuf)
 	};
 	struct cmsghdr *cmptr;
-#endif /* IP_PKTINFO */
-#ifdef IP_RECVIF
+#elif definded(IP_RECVIF)
 	char cmbuf[CMSG_SPACE(sizeof(struct sockaddr_dl))];
 	struct iovec iovec = {
 		.iov_base = bufr,
