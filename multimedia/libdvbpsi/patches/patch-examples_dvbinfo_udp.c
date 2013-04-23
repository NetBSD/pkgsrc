$NetBSD: patch-examples_dvbinfo_udp.c,v 1.1 2013/04/23 13:22:22 wiz Exp $

Portability fix from upstream (Jean-Paul Saman <jpsaman@videolan.org>).

--- examples/dvbinfo/udp.c.orig	2013-02-20 11:25:27.000000000 +0000
+++ examples/dvbinfo/udp.c
@@ -47,6 +47,16 @@
 #   include <arpa/inet.h>
 #endif
 
+#ifndef SOL_IP
+#   define SOL_IP IPPROTO_IP
+#endif
+#ifndef SOL_IPV6
+#   define SOL_IPV6 IPPROTO_IPV6
+#endif
+#ifndef IPPROTO_IPV6
+# define IPPROTO_IPV6 41 /* IANA */
+#endif
+
 #include <assert.h>
 
 #include "udp.h"
