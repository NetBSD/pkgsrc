$NetBSD: patch-src_network.c,v 1.1 2018/06/12 12:40:02 wiedi Exp $

Add include for FIONREAD on SunOS
--- src/network.c.orig	2018-03-31 13:12:24.000000000 +0000
+++ src/network.c
@@ -45,6 +45,10 @@
 #include <sys/types.h>
 #include <signal.h>
 
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
+
 #ifdef HAVE_NETINET_IN_H
 #  include <netinet/in.h>
 #endif
