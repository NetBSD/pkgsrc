$NetBSD: patch-src_ipc__listener.cpp,v 1.4.18.1 2021/11/20 22:15:24 tm Exp $

NetBSD<8 has SOCK_CLOEXEC -- but uses it with paccept, not accept4

--- src/ipc_listener.cpp.orig	2021-01-03 21:46:01.000000000 +0000
+++ src/ipc_listener.cpp
@@ -303,7 +303,11 @@ zmq::fd_t zmq::ipc_listener_t::accept ()
     //  resources is considered valid and treated by ignoring the connection.
     zmq_assert (_s != retired_fd);
 #if defined ZMQ_HAVE_SOCK_CLOEXEC && defined HAVE_ACCEPT4
+#if defined(__NetBSD__)
+    fd_t sock = ::paccept (_s, NULL, NULL, NULL, SOCK_CLOEXEC);
+#else
     fd_t sock = ::accept4 (_s, NULL, NULL, SOCK_CLOEXEC);
+#endif
 #else
     struct sockaddr_storage ss;
     memset (&ss, 0, sizeof (ss));
