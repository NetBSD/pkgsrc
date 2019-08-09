$NetBSD: patch-src_tcp__listener.cpp,v 1.5 2019/08/09 12:01:34 adam Exp $

NetBSD<8 has SOCK_CLOEXEC, but uses it with paccept, not accept4

--- src/tcp_listener.cpp.orig	2019-07-08 16:19:27.000000000 +0000
+++ src/tcp_listener.cpp
@@ -202,8 +202,13 @@ zmq::fd_t zmq::tcp_listener_t::accept ()
     socklen_t ss_len = sizeof (ss);
 #endif
 #if defined ZMQ_HAVE_SOCK_CLOEXEC && defined HAVE_ACCEPT4
+#if defined(__NetBSD__)
+    fd_t sock = ::paccept (_s, reinterpret_cast<struct sockaddr *> (&ss),
+                           &ss_len, NULL, SOCK_CLOEXEC);
+#else
     fd_t sock = ::accept4 (_s, reinterpret_cast<struct sockaddr *> (&ss),
                            &ss_len, SOCK_CLOEXEC);
+#endif
 #else
     fd_t sock =
       ::accept (_s, reinterpret_cast<struct sockaddr *> (&ss), &ss_len);
