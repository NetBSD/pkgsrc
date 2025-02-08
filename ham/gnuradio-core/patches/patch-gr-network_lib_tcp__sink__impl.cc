$NetBSD: patch-gr-network_lib_tcp__sink__impl.cc,v 1.1 2025/02/08 13:35:40 wiz Exp $

Fix build with boost 1.87.
https://github.com/gnuradio/gnuradio/pull/7554

--- gr-network/lib/tcp_sink_impl.cc.orig	2024-01-17 20:36:19.000000000 +0000
+++ gr-network/lib/tcp_sink_impl.cc
@@ -63,10 +63,8 @@ bool tcp_sink_impl::start()
 
         std::string s_port = std::to_string(d_port);
         asio::ip::tcp::resolver resolver(d_io_context);
-        asio::ip::tcp::resolver::query query(
-            d_host, s_port, asio::ip::resolver_query_base::passive);
-
-        d_endpoint = *resolver.resolve(query, err);
+        d_endpoint = *(
+            resolver.resolve(d_host, s_port, asio::ip::tcp::resolver::passive).cbegin());
 
         if (err) {
             throw std::runtime_error(
@@ -159,7 +157,7 @@ void tcp_sink_impl::connect(bool initial
             d_acceptor = new asio::ip::tcp::acceptor(
                 d_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), d_port));
     } else {
-        d_io_context.reset();
+        d_io_context.restart();
     }
 
     if (d_tcpsocket) {
@@ -194,7 +192,6 @@ bool tcp_sink_impl::stop()
         d_tcpsocket = NULL;
     }
 
-    d_io_context.reset();
     d_io_context.stop();
 
     if (d_acceptor) {
