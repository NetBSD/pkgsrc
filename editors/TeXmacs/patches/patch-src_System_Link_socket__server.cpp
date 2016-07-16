$NetBSD: patch-src_System_Link_socket__server.cpp,v 1.2 2016/07/16 21:13:22 wiz Exp $

--- src/System/Link/socket_server.cpp.orig	2015-12-16 16:15:03.000000000 +0000
+++ src/System/Link/socket_server.cpp
@@ -21,6 +21,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/wait.h>
+#include <sys/time.h>
+#include <sys/select.h>
 #else
 namespace wsoc {
 #include <sys/types.h>
