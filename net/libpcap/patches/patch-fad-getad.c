$NetBSD: patch-fad-getad.c,v 1.3 2026/09/30 18:58:34 adam Exp $

Re-order includes to avoid bpf_program re-definition.

--- fad-getad.c.orig	2026-09-13 11:16:31.000000000 +0000
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
@@ -62,6 +56,12 @@
 #include <netpacket/packet.h>
 #endif
 
+#include "pcap-int.h"
+
+#ifdef HAVE_OS_PROTO_H
+#include "os-proto.h"
+#endif
+
 /*
  * This is fun.
  *
