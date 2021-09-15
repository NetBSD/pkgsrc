$NetBSD: patch-src_network.c,v 1.2 2021/09/15 22:52:46 gdt Exp $

Add include for FIONREAD on SunOS

\todo File this patch upstream and include bugtracker URL.

--- src/network.c.orig	2021-09-13 23:33:26.000000000 +0000
+++ src/network.c
@@ -46,6 +46,10 @@
 #include <signal.h>
 #include <pthread.h>
 
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
+
 #ifdef HAVE_NETINET_IN_H
 #  include <netinet/in.h>
 #endif
