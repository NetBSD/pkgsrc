$NetBSD: patch-include_grpc_event__engine_port.h,v 1.7 2023/11/08 11:34:39 nros Exp $

<sys/filio.h> need for FIONREAD on Illumos/Solaris

--- include/grpc/event_engine/port.h.orig	2023-11-08 12:11:17.869350984 +0000
+++ include/grpc/event_engine/port.h
@@ -27,6 +27,9 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <unistd.h>
+#if defined(GPR_SOLARIS)
+#include <sys/filio.h>
+#endif
 #elif defined(GPR_WINDOWS)
 #include <winsock2.h>
 #include <ws2tcpip.h>
