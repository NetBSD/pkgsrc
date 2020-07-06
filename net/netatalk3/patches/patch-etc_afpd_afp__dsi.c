$NetBSD: patch-etc_afpd_afp__dsi.c,v 1.1 2020/07/06 20:19:54 christos Exp $

Turn on ipv4 encapsulation in v6 sockets

--- etc/afpd/afp_dsi.c.orig	2016-05-20 03:23:56.000000000 -0400
+++ etc/afpd/afp_dsi.c	2020-07-05 18:44:20.904366760 -0400
@@ -19,6 +19,7 @@
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/time.h>
 #ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
@@ -493,6 +494,12 @@
     int flag = 1;
     setsockopt(dsi->socket, SOL_TCP, TCP_NODELAY, &flag, sizeof(flag));
 
+#ifdef IPV6_V6ONLY
+    /* allow ipv4 encapsulation */
+    flag = 0;
+    setsockopt(dsi->socket, IPPROTO_IPV6, IPV6_V6ONLY, &flag, sizeof(flag));
+#endif
+
     ipc_child_state(obj, DSI_RUNNING);
 
     /* get stuck here until the end */
