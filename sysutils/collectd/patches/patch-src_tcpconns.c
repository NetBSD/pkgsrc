$NetBSD: patch-src_tcpconns.c,v 1.7 2017/11/21 15:18:23 fhajny Exp $

Include <sys/param.h>
Re-order to fix build on NetBSD.

--- src/tcpconns.c.orig	2017-11-18 09:03:27.370749644 +0000
+++ src/tcpconns.c
@@ -128,9 +128,9 @@
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
@@ -897,6 +897,7 @@ static int conn_init(void) {
   return 0;
 } /* int conn_init */
 
+#include <sys/param.h>
 static int conn_read(void) {
   struct inpcbtable table;
 #if !defined(__OpenBSD__) &&                                                   \
