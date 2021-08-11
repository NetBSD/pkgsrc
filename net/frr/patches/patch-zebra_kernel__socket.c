$NetBSD: patch-zebra_kernel__socket.c,v 1.2 2021/08/11 10:09:54 kardel Exp $

	Pass IFP interface index if known (normal case) to make
	interface specific routes work such as in

		ipv6 route ::/0 <ipv6 address> carp0 100
		ivv6 route ::/0 <other ipv6 address> 200

	frr-8 now enables SO_RERROR but exits cowardly when the
	routing socket returns ENOBUFS. ensure at least a bit more
	socket buffer space by increasing SO_RCVBUF.

--- zebra/kernel_socket.c.orig	2021-07-21 13:06:19.000000000 +0000
+++ zebra/kernel_socket.c
@@ -1243,6 +1243,19 @@ int rtm_write(int message, union sockuni
 #ifdef __OpenBSD__
 	SOCKADDRSET(mpls, RTA_SRC);
 #endif
+#ifdef __NetBSD__
+	if (index > 0) {
+		struct sockaddr_dl sdl;
+
+		memset(&sdl, 0, sizeof(sdl));
+		sdl.sdl_len = sizeof(sdl);
+		sdl.sdl_family = AF_LINK;
+		sdl.sdl_index = index;
+
+		msg.rtm.rtm_addrs |= RTA_IFP;
+		SOCKADDRSET(&sdl, RTA_IFP);
+	}
+#endif
 
 	msg.rtm.rtm_msglen = pnt - (caddr_t)&msg;
 
@@ -1425,6 +1438,9 @@ static void routing_socket(struct zebra_
 		return;
 	}
 
+	setsockopt_so_recvbuf(routing_sock, 1048576);
+	setsockopt_so_recvbuf(dplane_routing_sock, 1048576);
+
 #ifdef SO_RERROR
 	/* Allow reporting of route(4) buffer overflow errors */
 	int n = 1;
