$NetBSD: patch-fad-getad.c,v 1.2 2024/09/01 09:47:09 adam Exp $

Re-order includes to avoid bpf_program re-definition.

--- fad-getad.c.orig	2024-08-30 19:34:14.000000000 +0000
+++ fad-getad.c
@@ -46,12 +46,6 @@
 #include <string.h>
 #include <ifaddrs.h>
 
-#include "pcap-int.h"
-
-#ifdef HAVE_OS_PROTO_H
-#include "os-proto.h"
-#endif
-
 /*
  * We don't do this on Solaris 11 and later, as it appears there aren't
  * any AF_PACKET addresses on interfaces, so we don't need this, and
@@ -75,6 +69,12 @@
 # endif /* HAVE_NETPACKET_PACKET_H */
 #endif /* (defined(__linux__) || defined(__Lynx__)) && defined(AF_PACKET) */
 
+#include "pcap-int.h"
+
+#ifdef HAVE_OS_PROTO_H
+#include "os-proto.h"
+#endif
+
 /*
  * This is fun.
  *
