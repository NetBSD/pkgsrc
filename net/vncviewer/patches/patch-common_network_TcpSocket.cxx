$NetBSD: patch-common_network_TcpSocket.cxx,v 1.1 2011/08/06 14:38:52 cheusov Exp $

Fix for compilation failure on Linux
--- ../common/network/TcpSocket.cxx.orig   2006-05-15 19:56:20.000000000 +0300
+++ ../common/network/TcpSocket.cxx        2011-08-06 16:51:59.000000000 +0300
@@ -31,6 +31,7 @@
 #include <netinet/tcp.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <string.h>
 #include <signal.h>
