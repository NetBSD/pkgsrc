$NetBSD: patch-cpan_Socket_Socket.xs,v 1.1 2014/03/14 22:41:10 ryoon Exp $

* Fix build under SCO OpenServer 5.0.7/3.2

--- cpan/Socket/Socket.xs.orig	2014-01-06 22:46:43.000000000 +0000
+++ cpan/Socket/Socket.xs
@@ -75,6 +75,10 @@ NETINET_DEFINE_CONTEXT
 # define INADDR_LOOPBACK	 0x7F000001
 #endif /* INADDR_LOOPBACK */
 
+#if !defined(INET_ADDRSTRLEN)
+#define INET_ADDRSTRLEN		16
+#endif
+
 #ifndef C_ARRAY_LENGTH
 #define C_ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(*(arr)))
 #endif /* !C_ARRAY_LENGTH */
