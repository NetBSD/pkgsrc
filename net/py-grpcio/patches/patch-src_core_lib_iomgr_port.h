$NetBSD: patch-src_core_lib_iomgr_port.h,v 1.1 2018/10/22 15:42:46 jperkin Exp $

Support SunOS.

--- src/core/lib/iomgr/port.h.orig	2018-06-28 00:44:17.000000000 +0000
+++ src/core/lib/iomgr/port.h
@@ -139,6 +139,13 @@
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
