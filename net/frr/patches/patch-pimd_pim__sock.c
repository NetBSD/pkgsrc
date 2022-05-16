$NetBSD: patch-pimd_pim__sock.c,v 1.1 2022/05/16 11:54:20 kardel Exp $

	Support HAVE_STRUCT_IP_MREQN_IMR_IFINDEX and HAVE_IP_RECVIF

--- pimd/pim_sock.c.orig	2022-03-13 15:59:48.000000000 +0000
+++ pimd/pim_sock.c
@@ -27,7 +27,9 @@
 #include <unistd.h>
 #include <netdb.h>
 #include <errno.h>
-
+#ifdef __NetBSD__
+#include <net/if.h>
+#endif
 #include "log.h"
 #include "privs.h"
 #include "if.h"
@@ -97,11 +99,6 @@ int pim_socket_mcast(int protocol, struc
 		     uint8_t loop)
 {
 	int rcvbuf = 1024 * 1024 * 8;
-#ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
-	struct ip_mreqn mreq;
-#else
-	struct ip_mreq mreq;
-#endif
 	int fd;
 
 	fd = pim_socket_raw(protocol);
@@ -146,6 +143,15 @@ int pim_socket_mcast(int protocol, struc
 				"Could not set IP_RECVDSTADDR on socket fd=%d: errno=%d: %s",
 				fd, errno, safe_strerror(errno));
 		}
+#elif defined(HAVE_IP_RECVIF)
+		/* BSD IP_RECVIF */
+		int opt = 1;
+		if (setsockopt(fd, IPPROTO_IP, IP_RECVIF, &opt,
+			       sizeof(opt))) {
+			zlog_warn(
+				"Could not set IP_RECVDSTADDR on socket fd=%d: errno=%d: %s",
+				fd, errno, safe_strerror(errno));
+		}
 #else
 		flog_err(
 			EC_LIB_DEVELOPMENT,
@@ -208,23 +214,26 @@ int pim_socket_mcast(int protocol, struc
 		return PIM_SOCK_ERR_LOOP;
 	}
 
-	memset(&mreq, 0, sizeof(mreq));
+	{
 #ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
-	mreq.imr_ifindex = ifp->ifindex;
+		struct ip_mreqn mreq;
+
+		memset(&mreq, 0, sizeof(mreq));
+		mreq.imr_ifindex = ifp->ifindex;
+		if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, (void *)&mreq,
+		       	sizeof(mreq)))
 #else
-/*
- * I am not sure what to do here yet for *BSD
- */
-// mreq.imr_interface = ifindex;
+		uint32_t idx = htonl(ifp->ifindex);
+		if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, &idx, sizeof(idx)))
 #endif
 
-	if (setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, (void *)&mreq,
-		       sizeof(mreq))) {
-		zlog_warn(
-			"Could not set Outgoing Interface Option on socket fd=%d: errno=%d: %s",
-			fd, errno, safe_strerror(errno));
-		close(fd);
-		return PIM_SOCK_ERR_IFACE;
+		{
+			zlog_warn(
+				"Could not set Outgoing Interface Option on socket fd=%d: errno=%d: %s",
+				fd, errno, safe_strerror(errno));
+			close(fd);
+			return PIM_SOCK_ERR_IFACE;
+		}
 	}
 
 	if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, &rcvbuf, sizeof(rcvbuf)))
@@ -379,7 +388,7 @@ int pim_socket_recvfromto(int fd, uint8_
 			if (ifindex)
 				*ifindex = i->ipi_ifindex;
 
-			break;
+			continue;
 		}
 #endif
 
@@ -392,14 +401,20 @@ int pim_socket_recvfromto(int fd, uint8_
 			if (tolen)
 				*tolen = sizeof(struct sockaddr_in);
 
-			break;
+			continue;
 		}
 #endif
 
-#if defined(HAVE_IP_RECVIF) && defined(CMSG_IFINDEX)
-		if (cmsg->cmsg_type == IP_RECVIF)
-			if (ifindex)
-				*ifindex = CMSG_IFINDEX(cmsg);
+#if defined(HAVE_IP_RECVIF)
+		if (cmsg->cmsg_type == IP_RECVIF && ifindex) {
+#ifdef __NetBSD__
+			struct sockaddr_dl *dl = (struct sockaddr_dl *)CMSG_DATA(cmsg);
+			*ifindex = dl->sdl_index;
+#elif defined(CMSG_IFINDEX)
+			*ifindex = CMSG_IFINDEX(cmsg);
+#endif
+			continue;
+		}
 #endif
 
 	} /* for (cmsg) */
