$NetBSD: patch-lib_lwres_getaddrinfo.c,v 1.1.1.1.2.1 2014/12/10 19:53:09 tron Exp $

* Add fix for KAME based implementation.

--- lib/lwres/getaddrinfo.c.orig	2014-09-16 19:27:15.000000000 +0000
+++ lib/lwres/getaddrinfo.c
@@ -142,6 +142,10 @@
 #include <lwres/stdlib.h>
 #include <lwres/string.h>
 
+#ifdef __KAME__
+#include <net/if.h>
+#endif
+
 #define SA(addr)	((struct sockaddr *)(addr))
 #define SIN(addr)	((struct sockaddr_in *)(addr))
 #define SIN6(addr)	((struct sockaddr_in6 *)(addr))
@@ -366,14 +370,22 @@ lwres_getaddrinfo(const char *hostname, 
 			p = strchr(ntmp, '%');
 			ep = NULL;
 
+#ifdef __KAME__
+			if (p != NULL) {
+				scopeid = if_nametoindex(p + 1);
+				if (scopeid)
+					p = NULL;
+			}
+#endif
 			/*
 			 * Vendors may want to support non-numeric
 			 * scopeid around here.
 			 */
 
-			if (p != NULL)
+			if (p != NULL) {
 				scopeid = (lwres_uint32_t)strtoul(p + 1,
 								  &ep, 10);
+			}
 			if (p != NULL && ep != NULL && ep[0] == '\0')
 				*p = '\0';
 			else {
