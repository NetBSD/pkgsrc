$NetBSD: patch-gr-blocks_lib_socket__pdu__impl.cc,v 1.1 2019/07/08 17:50:55 ryoon Exp $

* Fix build with boost-1.70.0

--- gr-blocks/lib/socket_pdu_impl.cc.orig	2019-04-20 09:58:09.000000000 +0000
+++ gr-blocks/lib/socket_pdu_impl.cc
@@ -165,7 +165,7 @@ namespace gr {
     void
     socket_pdu_impl::start_tcp_accept()
     {
-      tcp_connection::sptr new_connection = tcp_connection::make(d_acceptor_tcp->get_io_service(), d_rxbuf.size(), d_tcp_no_delay);
+      tcp_connection::sptr new_connection = tcp_connection::make(static_cast<boost::asio::io_context&>(d_acceptor_tcp->get_executor().context()), d_rxbuf.size(), d_tcp_no_delay);
 
       d_acceptor_tcp->async_accept(new_connection->socket(),
         boost::bind(&socket_pdu_impl::handle_tcp_accept, this,
