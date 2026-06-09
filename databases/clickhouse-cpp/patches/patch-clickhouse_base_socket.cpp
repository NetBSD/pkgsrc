$NetBSD: patch-clickhouse_base_socket.cpp,v 1.1 2026/06/09 15:05:34 adam Exp $

--- clickhouse/base/socket.cpp.orig	2026-06-08 12:35:35.665324258 +0000
+++ clickhouse/base/socket.cpp
@@ -355,7 +355,7 @@ void Socket::SetTcpKeepAlive(int idle, int intvl, int 
 
 #if defined(_unix_)
     setsockopt(handle_, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));
-#   if defined(_linux_)
+#   if defined(_linux_) || defined(_bsd_)
         setsockopt(handle_, IPPROTO_TCP, TCP_KEEPIDLE, &idle, sizeof(idle));
 #   elif defined(_darwin_)
         setsockopt(handle_, IPPROTO_TCP, TCP_KEEPALIVE, &idle, sizeof(idle));
