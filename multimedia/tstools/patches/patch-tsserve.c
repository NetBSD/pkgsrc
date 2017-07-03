$NetBSD: patch-tsserve.c,v 1.1 2017/07/03 11:52:37 wiedi Exp $

no sin_len on SunOS
--- tsserve.c.orig	2008-11-06 23:15:49.000000000 +0000
+++ tsserve.c
@@ -3041,7 +3041,7 @@ static int run_server(tsserve_context_p
 
   // Bind it to port `listen_port` on this machine
   memset(&ipaddr,0,sizeof(ipaddr));
-#if !defined(__linux__) && !defined(_WIN32)
+#if !defined(__linux__) && !defined(_WIN32) && !defined(__sun)
   // On BSD, the length is defined in the datastructure
   ipaddr.sin_len = sizeof(struct sockaddr_in);
 #endif
