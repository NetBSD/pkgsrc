$NetBSD: patch-src_core_lib_iomgr_sockaddr__utils__posix.cc,v 1.1 2022/05/16 08:47:19 jperkin Exp $

Include sys/types.h before netinet.

--- src/core/lib/iomgr/sockaddr_utils_posix.cc.orig	2022-05-10 07:13:09.000000000 +0000
+++ src/core/lib/iomgr/sockaddr_utils_posix.cc
@@ -23,6 +23,8 @@
 #ifdef GRPC_POSIX_SOCKET_UTILS_COMMON
 
 #include "src/core/lib/iomgr/socket_utils.h"
+#include <sys/types.h>
+#include <sys/socket.h>
 #ifdef GRPC_LINUX_TCP_H
 #include <linux/tcp.h>
 #else
@@ -30,8 +32,6 @@
 #endif
 #include <stdio.h>
 #include <string.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 #include <string>
