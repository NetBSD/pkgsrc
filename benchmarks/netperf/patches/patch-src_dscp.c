$NetBSD: patch-src_dscp.c,v 1.1 2014/04/23 20:19:18 asau Exp $

--- src/dscp.c.orig	2012-04-03 23:51:29.000000000 +0000
+++ src/dscp.c
@@ -49,6 +49,9 @@ const char * iptos2str(int iptos);
  * Definitions for IP type of service (ip_tos)
  */
 
+#if defined(__FreeBSD__)
+#include <sys/types.h> /* u_int16_t */
+#endif
 #if HAVE_NETINET_IN_SYSTM_H
 #include <netinet/in_systm.h>
 #endif
