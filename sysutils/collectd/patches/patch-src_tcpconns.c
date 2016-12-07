$NetBSD: patch-src_tcpconns.c,v 1.6 2016/12/07 17:28:39 fhajny Exp $

Include <sys/param.h>
Re-order to fix build on NetBSD.

--- src/tcpconns.c.orig	2016-11-30 08:52:01.328910078 +0000
+++ src/tcpconns.c
@@ -111,9 +111,9 @@
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
@@ -820,6 +820,7 @@ static int conn_init(void) {
   return (0);
 } /* int conn_init */
 
+#include <sys/param.h>
 static int conn_read(void) {
   struct inpcbtable table;
 #if !defined(__OpenBSD__) &&                                                   \
