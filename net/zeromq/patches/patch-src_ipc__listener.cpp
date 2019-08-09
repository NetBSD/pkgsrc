$NetBSD: patch-src_ipc__listener.cpp,v 1.4 2019/08/09 12:01:34 adam Exp $

NetBSD<8 has SOCK_CLOEXEC -- but uses it with paccept, not accept4

--- src/ipc_listener.cpp.orig	2019-07-08 16:19:27.000000000 +0000
+++ src/ipc_listener.cpp
@@ -350,7 +350,11 @@ zmq::fd_t zmq::ipc_listener_t::accept ()
     //  resources is considered valid and treated by ignoring the connection.
     zmq_assert (_s != retired_fd);
 #if defined ZMQ_HAVE_SOCK_CLOEXEC && defined HAVE_ACCEPT4
+#if defined(__NetBSD__)
+    fd_t sock = ::paccept (_s, NULL, NULL, NULL, SOCK_CLOEXEC);
+#else
     fd_t sock = ::accept4 (_s, NULL, NULL, SOCK_CLOEXEC);
+#endif
 #else
     fd_t sock = ::accept (_s, NULL, NULL);
 #endif
