$NetBSD: patch-cbits_network-unix.c,v 1.1 2021/05/05 09:29:16 pho Exp $

Support NetBSD: https://github.com/jacobstanley/network-info/pull/21

--- cbits/network-unix.c.orig	2021-05-05 09:25:02.528519803 +0000
+++ cbits/network-unix.c
@@ -36,6 +36,10 @@
 #   include <netinet/in.h>
 #endif
 
+#ifdef __NetBSD__
+#   include <netinet/in.h>
+#endif
+
 #include "network.h"
 #include "common.h"
 
