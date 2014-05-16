$NetBSD: patch-cmd_lefty_os_unix_io.c,v 1.1 2014/05/16 12:29:04 ryoon Exp $

* Fix build under OpenBSD 5.5

--- cmd/lefty/os/unix/io.c.orig	2014-04-13 20:40:25.000000000 +0000
+++ cmd/lefty/os/unix/io.c
@@ -313,7 +313,11 @@ static FILE *serverconnect (char *name) 
 
     hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
     hints.ai_socktype = SOCK_STREAM;/* Stream socket */
+#if defined(AI_ADDRCONFIG)
     hints.ai_flags = AI_ADDRCONFIG | AI_NUMERICSERV;
+#else
+    hints.ai_flags = AI_NUMERICSERV;
+#endif
     hints.ai_protocol = 0;          /* Any protocol */
     hints.ai_canonname = NULL;
     hints.ai_addr = NULL;
