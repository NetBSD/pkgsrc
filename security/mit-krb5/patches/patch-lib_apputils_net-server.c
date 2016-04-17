$NetBSD: patch-lib_apputils_net-server.c,v 1.3 2016/04/17 15:33:13 kamil Exp $

--- lib/apputils/net-server.c.orig	2016-02-29 19:50:13.000000000 +0000
+++ lib/apputils/net-server.c
@@ -960,7 +960,9 @@ routing_update_needed(struct rt_msghdr *
             break;
 #endif
         return 1;
+#ifdef RTM_RESOLVE
     case RTM_RESOLVE:
+#endif
 #ifdef RTM_NEWMADDR
     case RTM_NEWMADDR:
     case RTM_DELMADDR:
@@ -1276,7 +1278,7 @@ send_to_from(int s, void *buf, size_t le
     msg.msg_controllen = 0;
 
     switch (from->sa_family) {
-#if defined(IP_PKTINFO)
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
     case AF_INET:
         if (fromlen != sizeof(struct sockaddr_in))
             goto use_sendto;
