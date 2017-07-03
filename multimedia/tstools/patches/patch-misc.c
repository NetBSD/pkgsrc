$NetBSD: patch-misc.c,v 1.1 2017/07/03 11:52:37 wiedi Exp $

no sin_len on SunOS
--- misc.c.orig	2008-11-06 23:15:49.000000000 +0000
+++ misc.c
@@ -1277,7 +1277,7 @@ extern int connect_socket(char *hostname
   }
   memcpy(&ipaddr.sin_addr.s_addr, hp->h_addr, hp->h_length);
   ipaddr.sin_family = hp->h_addrtype;
-#if !defined(__linux__)
+#if !defined(__linux__) && !defined(__sun)
   // On BSD, the length is defined in the datastructure
   ipaddr.sin_len = sizeof(struct sockaddr_in);
 #endif // __linux__
