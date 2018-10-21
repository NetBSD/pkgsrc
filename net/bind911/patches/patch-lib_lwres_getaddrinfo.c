$NetBSD: patch-lib_lwres_getaddrinfo.c,v 1.2 2018/10/21 15:51:14 taca Exp $

* Add fix for KAME based implementation.

--- lib/lwres/getaddrinfo.c.orig	2018-10-06 01:36:17.000000000 +0000
+++ lib/lwres/getaddrinfo.c
@@ -149,6 +149,10 @@
 #include <lwres/stdlib.h>
 #include <lwres/string.h>
 
+#ifdef __KAME__
+#include <net/if.h>
+#endif
+
 #define SA(addr)	((struct sockaddr *)(addr))
 #define SIN(addr)	((struct sockaddr_in *)(addr))
 #define SIN6(addr)	((struct sockaddr_in6 *)(addr))
