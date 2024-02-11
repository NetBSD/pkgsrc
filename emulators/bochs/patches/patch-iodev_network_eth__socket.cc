$NetBSD: patch-iodev_network_eth__socket.cc,v 1.2 2024/02/11 23:30:39 ryoon Exp $

--- iodev/network/eth_socket.cc.orig	2021-03-12 21:31:51.747171000 +0000
+++ iodev/network/eth_socket.cc
@@ -93,10 +93,10 @@ extern "C" {
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <netinet/in.h>
-#include <net/ethernet.h>
 #include <net/if.h>
 #ifdef __linux__
 #include <linux/types.h>
+#include <net/ethernet.h>
 #endif
 #include <netdb.h>
 #define closesocket(s) close(s)
