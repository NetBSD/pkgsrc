$NetBSD: patch-pimd_pim__mroute.c,v 1.1 2022/05/16 11:54:20 kardel Exp $

	Support HAVE_IP_RECVDSTADDR and HAVE_IP_RECVIF

--- pimd/pim_mroute.c.orig	2021-03-04 02:14:50.000000000 +0000
+++ pimd/pim_mroute.c
@@ -106,6 +106,26 @@ static int pim_mroute_set(struct pim_ins
 		}
 	}
 #endif
+#if defined(HAVE_IP_RECVDSTADDR)
+		/* BSD IP_RECVDSTADDR */
+		data = 1;
+		if (setsockopt(pim->mroute_socket, IPPROTO_IP, IP_RECVDSTADDR, &data,
+			       data_len)) {
+			zlog_warn(
+				"Could not set IP_RECVDSTADDR on socket fd=%d: errno=%d: %s",
+				pim->mroute_socket, errno, safe_strerror(errno));
+		}
+#endif
+#if defined(HAVE_IP_RECVIF)
+		/* BSD IP_RECVIF */
+		data = 1;
+		if (setsockopt(pim->mroute_socket, IPPROTO_IP, IP_RECVIF, &data,
+			       data_len)) {
+			zlog_warn(
+				"Could not set IP_RECVIF on socket fd=%d: errno=%d: %s",
+				pim->mroute_socket, errno, safe_strerror(errno));
+		}
+#endif
 
 	setsockopt_so_recvbuf(pim->mroute_socket, 1024 * 1024 * 8);
 
