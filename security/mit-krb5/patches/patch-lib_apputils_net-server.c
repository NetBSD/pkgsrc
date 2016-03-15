$NetBSD: patch-lib_apputils_net-server.c,v 1.2 2016/03/15 15:16:39 tez Exp $

--- lib/apputils/net-server.c.orig	2013-08-30 12:14:00.000000000 +0000
+++ lib/apputils/net-server.c
@@ -1477,7 +1477,7 @@ send_to_from(int s, void *buf, size_t le
     msg.msg_controllen = 0;
 
     switch (from->sa_family) {
-#if defined(IP_PKTINFO)
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
     case AF_INET:
         if (fromlen != sizeof(struct sockaddr_in))
             goto use_sendto;
