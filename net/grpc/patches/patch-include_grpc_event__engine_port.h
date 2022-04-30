$NetBSD: patch-include_grpc_event__engine_port.h,v 1.5 2022/04/30 21:36:26 wiz Exp $

Support NetBSD.
https://github.com/grpc/grpc/pull/29542

--- include/grpc/event_engine/port.h.orig	2021-09-25 02:33:41.000000000 +0000
+++ include/grpc/event_engine/port.h
@@ -20,7 +20,7 @@
 #if defined(GPR_ANDROID) || defined(GPR_LINUX) || defined(GPR_APPLE) ||     \
     defined(GPR_FREEBSD) || defined(GPR_OPENBSD) || defined(GPR_SOLARIS) || \
     defined(GPR_AIX) || defined(GPR_NACL) || defined(GPR_FUCHSIA) ||        \
-    defined(GRPC_POSIX_SOCKET)
+    defined(GRPC_POSIX_SOCKET) || defined(GPR_NETBSD)
 #define GRPC_EVENT_ENGINE_POSIX
 #include <arpa/inet.h>
 #include <netdb.h>
