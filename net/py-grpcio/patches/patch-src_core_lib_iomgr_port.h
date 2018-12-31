$NetBSD: patch-src_core_lib_iomgr_port.h,v 1.2 2018/12/31 23:03:02 leot Exp $

Support NetBSD.
Support SunOS.

--- src/core/lib/iomgr/port.h.orig	2018-06-28 00:44:17.000000000 +0000
+++ src/core/lib/iomgr/port.h
@@ -139,6 +139,24 @@
 #define GRPC_POSIX_SOCKET 1
 #define GRPC_POSIX_SOCKETUTILS 1
 #define GRPC_POSIX_WAKEUP_FD 1
+#elif defined(GPR_NETBSD)
+#define GRPC_HAVE_ARPA_NAMESER 1
+#define GRPC_HAVE_IFADDRS 1
+#define GRPC_HAVE_IPV6_RECVPKTINFO 1
+#define GRPC_HAVE_SO_NOSIGPIPE 1
+#define GRPC_HAVE_UNIX_SOCKET 1
+#define GRPC_POSIX_FORK 1
+#define GRPC_POSIX_NO_SPECIAL_WAKEUP_FD 1
+#define GRPC_POSIX_SOCKET 1
+#define GRPC_POSIX_SOCKETUTILS 1
+#define GRPC_POSIX_WAKEUP_FD 1
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
