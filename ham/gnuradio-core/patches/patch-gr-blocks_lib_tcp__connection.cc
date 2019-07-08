$NetBSD: patch-gr-blocks_lib_tcp__connection.cc,v 1.1 2019/07/08 17:50:55 ryoon Exp $

* Fix build with boost-1.70.0

--- gr-blocks/lib/tcp_connection.cc.orig	2019-04-20 09:58:09.000000000 +0000
+++ gr-blocks/lib/tcp_connection.cc
@@ -31,12 +31,12 @@
 namespace gr {
   namespace blocks {
 
-    tcp_connection::sptr tcp_connection::make(boost::asio::io_service& io_service, int MTU/*= 10000*/, bool no_delay/*=false*/)
+    tcp_connection::sptr tcp_connection::make(boost::asio::io_context& io_service, int MTU/*= 10000*/, bool no_delay/*=false*/)
     {
       return sptr(new tcp_connection(io_service, MTU, no_delay));
     }
 
-    tcp_connection::tcp_connection(boost::asio::io_service& io_service, int MTU/*= 10000*/, bool no_delay/*=false*/)
+    tcp_connection::tcp_connection(boost::asio::io_context& io_service, int MTU/*= 10000*/, bool no_delay/*=false*/)
       : d_socket(io_service)
       , d_block(NULL)
       , d_no_delay(no_delay)
