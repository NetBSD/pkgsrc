$NetBSD: patch-protocol_discovery_mdns.c,v 1.2 2016/02/28 20:37:28 schnoebe Exp $

Add <sys/time> to allow building on a wider variety of systems.

--- protocol/discovery/mdns.c.orig	2015-12-05 13:17:06.000000000 +0000
+++ protocol/discovery/mdns.c
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <syslog.h>
 #include <sys/socket.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
