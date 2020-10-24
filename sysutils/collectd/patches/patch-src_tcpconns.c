$NetBSD: patch-src_tcpconns.c,v 1.8 2020/10/24 22:39:45 wiz Exp $

Include <sys/param.h>
Re-order to fix build on NetBSD.

--- src/tcpconns.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/tcpconns.c	2020-07-06 20:25:33.959459766 +0200
@@ -127,9 +127,9 @@
 #include <net/route.h>
 #include <netdb.h>
 #include <netinet/in.h>
+#include <netinet/ip.h>
 #include <netinet/in_pcb.h>
 #include <netinet/in_systm.h>
-#include <netinet/ip.h>
 #include <netinet/ip_var.h>
 #include <netinet/tcp.h>
 #include <netinet/tcp_timer.h>
@@ -895,6 +895,7 @@ static int conn_init(void) {
   return 0;
 } /* int conn_init */
 
+#include <sys/param.h>
 static int conn_read(void) {
   struct inpcbtable table;
 #if !defined(__OpenBSD__) &&                                                   \
