$NetBSD: patch-src_TLSServer.cpp,v 1.1 2018/09/02 09:53:14 triaxx Exp $

errno.h is also required on NetBSD

--- src/TLSServer.cpp.orig	2015-05-10 21:35:22.000000000 +0000
+++ src/TLSServer.cpp
@@ -38,7 +38,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#if (defined OPENBSD || defined SOLARIS)
+#if (defined OPENBSD || defined SOLARIS || defined NETBSD)
 #include <errno.h>
 #else
 #include <sys/errno.h>
