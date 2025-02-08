$NetBSD: patch-gr-network_lib_udp__sink__impl.cc,v 1.1 2025/02/08 13:35:40 wiz Exp $

Fix build with boost 1.87.
https://github.com/gnuradio/gnuradio/pull/7554

--- gr-network/lib/udp_sink_impl.cc.orig	2024-01-17 20:36:19.000000000 +0000
+++ gr-network/lib/udp_sink_impl.cc
@@ -125,11 +125,10 @@ bool udp_sink_impl::start()
     std::string str_port = std::to_string(d_port);
     std::string str_host = d_host.empty() ? std::string("localhost") : d_host;
     asio::ip::udp::resolver resolver(d_io_context);
-    asio::ip::udp::resolver::query query(
-        str_host, str_port, asio::ip::resolver_query_base::passive);
-
     asio::error_code err;
-    d_endpoint = *resolver.resolve(query, err);
+    d_endpoint =
+        *(resolver.resolve(str_host, str_port, asio::ip::tcp::resolver::passive, err)
+              .cbegin());
 
     if (err) {
         throw std::runtime_error(std::string("[UDP Sink] Unable to resolve host/IP: ") +
@@ -177,7 +176,6 @@ bool udp_sink_impl::stop()
         delete d_udpsocket;
         d_udpsocket = nullptr;
 
-        d_io_context.reset();
         d_io_context.stop();
     }
 
