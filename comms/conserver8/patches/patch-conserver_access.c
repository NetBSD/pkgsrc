$NetBSD: patch-conserver_access.c,v 1.1.2.2 2017/02/15 19:39:10 bsiegert Exp $

Make sure to use correct sockaddr length when doing getnameinfo().

--- conserver/access.c.orig	2017-01-18 09:20:03.000000000 +0000
+++ conserver/access.c
@@ -150,6 +150,7 @@ AccType(INADDR_STYPE *addr, char **peern
     so = sizeof(*addr);
 
 #if USE_IPV6
+    so = sizeof(struct sockaddr_in6);
     error =
 	getnameinfo((struct sockaddr *)addr, so, ipaddr, sizeof(ipaddr),
 		    NULL, 0, NI_NUMERICHOST);
