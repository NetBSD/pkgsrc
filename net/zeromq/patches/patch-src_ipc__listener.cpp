$NetBSD: patch-src_ipc__listener.cpp,v 1.3 2018/01/13 18:22:42 adam Exp $

NetBSD<8 has SOCK_CLOEXEC -- but uses it with paccept, not accept4

--- src/ipc_listener.cpp.orig	2017-12-13 13:37:08.000000000 +0000
+++ src/ipc_listener.cpp
@@ -383,7 +383,11 @@ zmq::fd_t zmq::ipc_listener_t::accept ()
     //  resources is considered valid and treated by ignoring the connection.
     zmq_assert (s != retired_fd);
 #if defined ZMQ_HAVE_SOCK_CLOEXEC && defined HAVE_ACCEPT4
+#if defined(__NetBSD__)
+    fd_t sock = ::paccept (s, NULL, NULL, NULL, SOCK_CLOEXEC);
+#else
     fd_t sock = ::accept4 (s, NULL, NULL, SOCK_CLOEXEC);
+#endif
 #else
     fd_t sock = ::accept (s, NULL, NULL);
 #endif
