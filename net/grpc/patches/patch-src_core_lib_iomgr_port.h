$NetBSD: patch-src_core_lib_iomgr_port.h,v 1.1 2018/05/15 15:20:18 jperkin Exp $

Add SunOS support.

--- src/core/lib/iomgr/port.h.orig	2018-04-13 18:08:11.000000000 +0000
+++ src/core/lib/iomgr/port.h
@@ -120,6 +120,13 @@
 #define GRPC_POSIX_SOCKET 1
 #define GRPC_POSIX_SOCKETUTILS 1
 #define GRPC_POSIX_WAKEUP_FD 1
+#elif defined(GPR_SUNOS)
+#define GRPC_HAVE_UNIX_SOCKET 1
+#define GRPC_POSIX_FORK 1
+#define GRPC_POSIX_NO_SPECIAL_WAKEUP_FD 1
+#define GRPC_POSIX_SOCKET 1
+#define GRPC_POSIX_SOCKETUTILS 1
+#define GRPC_POSIX_WAKEUP_FD 1
 #elif defined(GPR_NACL)
 #define GRPC_HAVE_ARPA_NAMESER 1
 #define GRPC_POSIX_NO_SPECIAL_WAKEUP_FD 1
