$NetBSD: patch-src_lib_asiolink_tcp__endpoint.h,v 1.1 2025/01/15 06:05:14 wiz Exp $

Fix build with boost 1.87.
https://github.com/isc-projects/kea/pull/143

--- src/lib/asiolink/tcp_endpoint.h.orig	2024-07-25 08:50:58.000000000 +0000
+++ src/lib/asiolink/tcp_endpoint.h
@@ -42,7 +42,7 @@ public:
     /// \param port The TCP port number of the endpoint.
     TCPEndpoint(const IOAddress& address, const unsigned short port) :
         asio_endpoint_placeholder_(
-            new boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(address.toText()),
+            new boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(address.toText()),
                               port)),
         asio_endpoint_(*asio_endpoint_placeholder_)
     {}
