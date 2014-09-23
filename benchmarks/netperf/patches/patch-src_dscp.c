$NetBSD: patch-src_dscp.c,v 1.2 2014/09/23 13:55:00 jperkin Exp $

SunOS needs sys/types.h.

--- src/dscp.c.orig	2012-04-03 23:51:29.000000000 +0000
+++ src/dscp.c
@@ -49,6 +49,9 @@ const char * iptos2str(int iptos);
  * Definitions for IP type of service (ip_tos)
  */
 
+#if defined(__FreeBSD__) || defined(__sun)
+#include <sys/types.h> /* u_int16_t */
+#endif
 #if HAVE_NETINET_IN_SYSTM_H
 #include <netinet/in_systm.h>
 #endif
