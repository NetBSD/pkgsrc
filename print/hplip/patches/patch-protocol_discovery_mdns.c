$NetBSD: patch-protocol_discovery_mdns.c,v 1.3 2022/08/26 03:08:28 khorben Exp $

Add system headers to allow building on a wider variety of systems.

--- protocol/discovery/mdns.c.orig	2019-12-10 05:00:36.000000000 +0000
+++ protocol/discovery/mdns.c
@@ -24,10 +24,12 @@
  Author: Sanjay Kumar
  \*****************************************************************************/
 
-//#include <stdio.h>
+#include <unistd.h>
+#include <stdio.h>
 #include <string.h>
 #include <syslog.h>
 #include <sys/socket.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
