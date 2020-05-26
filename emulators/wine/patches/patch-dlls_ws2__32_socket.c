$NetBSD: patch-dlls_ws2__32_socket.c,v 1.1 2020/05/26 15:20:23 adam Exp $

Conditionally use RFC3678 socket options.

--- dlls/ws2_32/socket.c.orig	2020-05-25 20:28:31.195748937 +0000
+++ dlls/ws2_32/socket.c
@@ -692,10 +692,12 @@ static const int ws_ip_map[][2] =
     MAP_OPTION( IP_MULTICAST_LOOP ),
     MAP_OPTION( IP_ADD_MEMBERSHIP ),
     MAP_OPTION( IP_DROP_MEMBERSHIP ),
+#ifdef IP_UNBLOCK_SOURCE
     MAP_OPTION( IP_ADD_SOURCE_MEMBERSHIP ),
     MAP_OPTION( IP_DROP_SOURCE_MEMBERSHIP ),
     MAP_OPTION( IP_BLOCK_SOURCE ),
     MAP_OPTION( IP_UNBLOCK_SOURCE ),
+#endif
     MAP_OPTION( IP_OPTIONS ),
 #ifdef IP_HDRINCL
     MAP_OPTION( IP_HDRINCL ),
@@ -5776,7 +5778,9 @@ int WINAPI WS_setsockopt(SOCKET s, int l
     int woptval;
     struct linger linger;
     struct timeval tval;
+#ifdef IP_BLOCK_SOURCE
     struct ip_mreq_source mreq_source;
+#endif
 
     TRACE("(socket %04lx, %s, optval %s, optlen %d)\n", s,
           debugstr_sockopt(level, optname), debugstr_optval(optval, optlen),
@@ -5987,6 +5991,7 @@ int WINAPI WS_setsockopt(SOCKET s, int l
     case WS_IPPROTO_IP:
         switch(optname)
         {
+#ifdef IP_BLOCK_SOURCE
         case WS_IP_ADD_SOURCE_MEMBERSHIP:
         case WS_IP_DROP_SOURCE_MEMBERSHIP:
         case WS_IP_BLOCK_SOURCE:
@@ -6003,6 +6008,7 @@ int WINAPI WS_setsockopt(SOCKET s, int l
             convert_sockopt(&level, &optname);
             break;
         }
+#endif
         case WS_IP_ADD_MEMBERSHIP:
         case WS_IP_DROP_MEMBERSHIP:
 #ifdef IP_HDRINCL
