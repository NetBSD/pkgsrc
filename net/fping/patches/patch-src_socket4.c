$NetBSD: patch-src_socket4.c,v 1.1 2016/12/29 15:04:29 he Exp $

Fix for building on NetBSD 6.0, also works on 7.0.

--- src/socket4.c.orig	2015-10-21 19:02:56.000000000 +0000
+++ src/socket4.c
@@ -35,6 +35,9 @@
 
 #include <sys/socket.h>
 #include <netinet/in.h>
+#ifdef __NetBSD__
+#include <netinet/in_systm.h>	/* for n_time */
+#endif /* __NetBSD__ */
 #include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 #include <netdb.h>
