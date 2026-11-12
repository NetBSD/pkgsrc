$NetBSD: patch-src_System_Link_socket__notifier.cpp,v 1.1 2026/11/12 10:32:43 nros Exp $

* add missing include
  sys/select.h for select(), FD_ISSET and struct timeval
  Fixes build on NetBSD 11

--- src/System/Link/socket_notifier.cpp.orig	2025-11-17 10:52:51.000000000 +0000
+++ src/System/Link/socket_notifier.cpp
@@ -25,6 +25,7 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
+#include <sys/select.h>
 #endif
 #include <errno.h>
 
