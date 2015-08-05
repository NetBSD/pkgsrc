$NetBSD: patch-src_System_Link_socket__server.cpp,v 1.1 2015/08/05 13:09:17 ryoon Exp $

--- src/System/Link/socket_server.cpp.orig	2014-03-03 11:44:14.000000000 +0000
+++ src/System/Link/socket_server.cpp
@@ -21,6 +21,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/wait.h>
+#include <sys/time.h>
+#include <sys/select.h>
 #endif
 
 hashset<pointer> socket_server_set;
