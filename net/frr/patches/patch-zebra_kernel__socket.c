$NetBSD: patch-zebra_kernel__socket.c,v 1.1 2020/12/10 16:43:24 kardel Exp $

	Pass IFP interface index if known (normal case) to make
	interface specific routes work such as in

		ipv6 route ::/0 <ipv6 address> carp0 100
		ivv6 route ::/0 <other ipv6 address> 200

--- zebra/kernel_socket.c.orig	2020-06-30 11:08:57.000000000 +0000
+++ zebra/kernel_socket.c
@@ -1277,6 +1277,19 @@ int rtm_write(int message, union sockuni
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
 
