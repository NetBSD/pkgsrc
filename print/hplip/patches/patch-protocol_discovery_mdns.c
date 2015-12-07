$NetBSD: patch-protocol_discovery_mdns.c,v 1.1 2015/12/07 11:02:26 adam Exp $

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
