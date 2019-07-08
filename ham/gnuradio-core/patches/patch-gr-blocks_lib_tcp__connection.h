$NetBSD: patch-gr-blocks_lib_tcp__connection.h,v 1.1 2019/07/08 17:50:55 ryoon Exp $

* Fix build with boost-1.70.0

--- gr-blocks/lib/tcp_connection.h.orig	2019-04-20 09:58:09.000000000 +0000
+++ gr-blocks/lib/tcp_connection.h
@@ -42,12 +42,12 @@ namespace gr {
       basic_block *d_block;
       bool d_no_delay;
 
-      tcp_connection(boost::asio::io_service& io_service, int MTU=10000, bool no_delay=false);
+      tcp_connection(boost::asio::io_context& io_service, int MTU=10000, bool no_delay=false);
 
     public:
       typedef boost::shared_ptr<tcp_connection> sptr;
 
-      static sptr make(boost::asio::io_service& io_service, int MTU=10000, bool no_delay=false);
+      static sptr make(boost::asio::io_context& io_service, int MTU=10000, bool no_delay=false);
 
       boost::asio::ip::tcp::socket& socket() { return d_socket; };
 
