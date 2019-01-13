$NetBSD: patch-iodev_network_eth__socket.cc,v 1.1 2019/01/13 11:59:38 ryoon Exp $

--- iodev/network/eth_socket.cc.orig	2017-03-30 18:08:15.000000000 +0000
+++ iodev/network/eth_socket.cc
@@ -83,12 +83,14 @@ extern "C" {
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
-#include <netpacket/packet.h>
 #include <netinet/in.h>
-#include <net/ethernet.h>
 #include <net/if.h>
-#include <linux/types.h>
 #include <netdb.h>
+#if defined(__linux__)
+#include <netpacket/packet.h>
+#include <net/ethernet.h>
+#include <linux/types.h>
+#endif
 #define closesocket(s) close(s)
 typedef int SOCKET;
 #ifndef INVALID_SOCKET
