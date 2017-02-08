$NetBSD: patch-src_tcp__listener.cpp,v 1.2 2017/02/08 18:15:44 maya Exp $

NetBSD<8 has SOCK_CLOEXEC, but uses it with paccept, not accept4

--- src/tcp_listener.cpp.orig	2016-12-31 15:25:47.000000000 +0000
+++ src/tcp_listener.cpp
@@ -274,7 +274,11 @@ zmq::fd_t zmq::tcp_listener_t::accept ()
     socklen_t ss_len = sizeof (ss);
 #endif
 #if defined ZMQ_HAVE_SOCK_CLOEXEC
+#if defined(__NetBSD__)
+    fd_t sock = ::paccept (s, (struct sockaddr *) &ss, &ss_len, NULL, SOCK_CLOEXEC);
+#else
     fd_t sock = ::accept4 (s, (struct sockaddr *) &ss, &ss_len, SOCK_CLOEXEC);
+#endif
 #else
     fd_t sock = ::accept (s, (struct sockaddr *) &ss, &ss_len);
 #endif
