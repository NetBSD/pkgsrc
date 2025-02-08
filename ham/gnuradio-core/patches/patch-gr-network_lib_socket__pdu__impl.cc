$NetBSD: patch-gr-network_lib_socket__pdu__impl.cc,v 1.1 2025/02/08 13:35:40 wiz Exp $

Fix build with boost 1.87.
https://github.com/gnuradio/gnuradio/pull/7554

--- gr-network/lib/socket_pdu_impl.cc.orig	2024-01-17 20:36:19.000000000 +0000
+++ gr-network/lib/socket_pdu_impl.cc
@@ -54,9 +54,12 @@ socket_pdu_impl::socket_pdu_impl(std::st
         d_tcp_endpoint = asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port_num);
     } else if ((type == "TCP_SERVER") || (type == "TCP_CLIENT")) {
         asio::ip::tcp::resolver resolver(d_io_context);
-        asio::ip::tcp::resolver::query query(
-            asio::ip::tcp::v4(), addr, port, asio::ip::resolver_query_base::passive);
-        d_tcp_endpoint = *resolver.resolve(query);
+        d_tcp_endpoint = *(resolver
+                               .resolve(asio::ip::tcp::v4(),
+                                        addr,
+                                        port,
+                                        asio::ip::resolver_query_base::passive)
+                               .cbegin());
     } else if ((type == "UDP_SERVER") &&
                ((addr.empty()) || (addr == "0.0.0.0"))) { // Bind on all interfaces
         int port_num = atoi(port.c_str());
@@ -66,13 +69,21 @@ socket_pdu_impl::socket_pdu_impl(std::st
         d_udp_endpoint = asio::ip::udp::endpoint(asio::ip::udp::v4(), port_num);
     } else if ((type == "UDP_SERVER") || (type == "UDP_CLIENT")) {
         asio::ip::udp::resolver resolver(d_io_context);
-        asio::ip::udp::resolver::query query(
-            asio::ip::udp::v4(), addr, port, asio::ip::resolver_query_base::passive);
 
         if (type == "UDP_SERVER")
-            d_udp_endpoint = *resolver.resolve(query);
+            d_udp_endpoint = *(resolver
+                                   .resolve(asio::ip::udp::v4(),
+                                            addr,
+                                            port,
+                                            asio::ip::resolver_query_base::passive)
+                                   .cbegin());
         else
-            d_udp_endpoint_other = *resolver.resolve(query);
+            d_udp_endpoint_other = *(resolver
+                                         .resolve(asio::ip::udp::v4(),
+                                                  addr,
+                                                  port,
+                                                  asio::ip::resolver_query_base::passive)
+                                         .cbegin());
     }
 
     if (type == "TCP_SERVER") {
