$NetBSD: patch-torch_csrc_distributed_c10d_socket.cpp,v 1.1 2025/01/23 14:31:16 ryoon Exp $

* NetBSD has no AI_V4MAPPED and AI_ALL.

--- torch/csrc/distributed/c10d/socket.cpp.orig	2025-01-21 16:40:38.577733771 +0000
+++ torch/csrc/distributed/c10d/socket.cpp
@@ -809,6 +809,13 @@ std::unique_ptr<SocketImpl> SocketConnec
       SocketError, fmt::format("{} {}", msg, fmt::join(errors_, " ")));
 }
 
+#if !defined(AI_V4MAPPED)
+#define AI_V4MAPPED 0x00000000
+#endif
+#if !defined(AI_ALL)
+#define AI_ALL 0x00000000
+#endif
+
 bool SocketConnectOp::tryConnect(int family) {
   ::addrinfo hints{};
   hints.ai_flags = AI_V4MAPPED | AI_ALL | AI_NUMERICSERV;
