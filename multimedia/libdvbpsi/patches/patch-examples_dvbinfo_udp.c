$NetBSD: patch-examples_dvbinfo_udp.c,v 1.2 2013/10/05 08:29:38 wiz Exp $

Portability fix from upstream (Jean-Paul Saman <jpsaman@videolan.org>).

--- examples/dvbinfo/udp.c.orig	2013-10-02 10:19:18.000000000 +0000
+++ examples/dvbinfo/udp.c
@@ -61,6 +61,16 @@
 #   include <fcntl.h>
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
