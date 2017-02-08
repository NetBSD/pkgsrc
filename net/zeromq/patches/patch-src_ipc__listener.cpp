$NetBSD: patch-src_ipc__listener.cpp,v 1.2 2017/02/08 18:15:44 maya Exp $

NetBSD<8 has SOCK_CLOEXEC -- but uses it with paccept, not accept4

--- src/ipc_listener.cpp.orig	2016-12-31 15:25:47.000000000 +0000
+++ src/ipc_listener.cpp
@@ -391,7 +391,11 @@ zmq::fd_t zmq::ipc_listener_t::accept ()
     //  resources is considered valid and treated by ignoring the connection.
     zmq_assert (s != retired_fd);
 #if defined ZMQ_HAVE_SOCK_CLOEXEC
+#if defined(__NetBSD__)
+    fd_t sock = ::paccept (s, NULL, NULL, NULL, SOCK_CLOEXEC);
+#else
     fd_t sock = ::accept4 (s, NULL, NULL, SOCK_CLOEXEC);
+#endif
 #else
     fd_t sock = ::accept (s, NULL, NULL);
 #endif
