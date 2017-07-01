$NetBSD: patch-plugin_handler__socket_libhsclient_socket.cpp,v 1.1 2017/07/01 22:11:39 joerg Exp $

--- plugin/handler_socket/libhsclient/socket.cpp.orig	2017-07-01 21:41:53.251263916 +0000
+++ plugin/handler_socket/libhsclient/socket.cpp
@@ -14,6 +14,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
+#include <sys/time.h>
 #include <sys/un.h>
 
 #include "socket.hpp"
