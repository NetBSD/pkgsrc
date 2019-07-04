$NetBSD: patch-fad-getad.c,v 1.1 2019/07/04 07:17:25 adam Exp $

Re-order includes to avoid bpf_program re-definition.

--- fad-getad.c.orig	2014-11-13 08:58:52.000000000 +0000
+++ fad-getad.c
@@ -49,12 +49,6 @@
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
@@ -78,6 +72,12 @@
 # endif /* HAVE_NETPACKET_PACKET_H */
 #endif /* (defined(linux) || defined(__Lynx__)) && defined(AF_PACKET) */
 
+#include "pcap-int.h"
+
+#ifdef HAVE_OS_PROTO_H
+#include "os-proto.h"
+#endif
+
 /*
  * This is fun.
  *
