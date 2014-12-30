$NetBSD: patch-tools_parser_tcpip.c,v 1.1 2014/12/30 08:39:13 plunky Exp $

BSD vs Linux differences

--- tools/parser/tcpip.c.orig	2012-12-24 17:46:55.000000000 +0000
+++ tools/parser/tcpip.c
@@ -31,8 +31,9 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include <net/ethernet.h>
+#include <net/if.h>
 #include <netinet/in.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
 #include <netinet/if_ether.h>
