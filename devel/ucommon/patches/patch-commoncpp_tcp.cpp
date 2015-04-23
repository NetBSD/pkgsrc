$NetBSD: patch-commoncpp_tcp.cpp,v 1.1 2015/04/23 18:25:15 joerg Exp $

--- commoncpp/tcp.cpp.orig	2015-04-23 14:03:06.000000000 +0000
+++ commoncpp/tcp.cpp
@@ -457,8 +457,8 @@ TCPStream::TCPStream(TCPV6Socket &server
 #endif
 
 TCPStream::TCPStream(const IPV4Host &host, tpport_t port, unsigned size, bool throwflag, timeout_t to) :
-    streambuf(), Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
-    ,iostream(),
+    streambuf(), Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP),
+    iostream((streambuf *)this),
     bufsize(0),gbuf(NULL),pbuf(NULL) {
     family = IPV4;
     timeout = to;
