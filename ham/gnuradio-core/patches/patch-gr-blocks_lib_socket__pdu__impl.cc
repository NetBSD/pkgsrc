$NetBSD: patch-gr-blocks_lib_socket__pdu__impl.cc,v 1.2 2020/05/09 15:17:51 joerg Exp $

* Fix build with boost-1.70.0

--- gr-blocks/lib/socket_pdu_impl.cc.orig	2019-04-20 09:58:09.000000000 +0000
+++ gr-blocks/lib/socket_pdu_impl.cc
@@ -86,7 +86,7 @@ namespace gr {
 
         start_tcp_accept();
 
-        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::tcp_server_send, this, _1));
+        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::tcp_server_send, this, boost::placeholders::_1));
       }
       else if (type =="TCP_CLIENT") {
         boost::system::error_code error = boost::asio::error::host_not_found;
@@ -96,7 +96,7 @@ namespace gr {
             throw boost::system::system_error(error);
         d_tcp_socket->set_option(boost::asio::ip::tcp::no_delay(d_tcp_no_delay));
 
-        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::tcp_client_send, this, _1));
+        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::tcp_client_send, this, boost::placeholders::_1));
 
         d_tcp_socket->async_read_some(boost::asio::buffer(d_rxbuf),
           boost::bind(&socket_pdu_impl::handle_tcp_read, this,
@@ -110,7 +110,7 @@ namespace gr {
             boost::asio::placeholders::error,
             boost::asio::placeholders::bytes_transferred));
 
-        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::udp_send, this, _1));
+        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::udp_send, this, boost::placeholders::_1));
       }
       else if (type =="UDP_CLIENT") {
         d_udp_socket.reset(new boost::asio::ip::udp::socket(d_io_service, d_udp_endpoint));
@@ -119,7 +119,7 @@ namespace gr {
             boost::asio::placeholders::error,
             boost::asio::placeholders::bytes_transferred));
 
-        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::udp_send, this, _1));
+        set_msg_handler(pdu::pdu_port_id(), boost::bind(&socket_pdu_impl::udp_send, this, boost::placeholders::_1));
       }
       else
         throw std::runtime_error("gr::blocks:socket_pdu: unknown socket type");
@@ -165,7 +165,7 @@ namespace gr {
     void
     socket_pdu_impl::start_tcp_accept()
     {
-      tcp_connection::sptr new_connection = tcp_connection::make(d_acceptor_tcp->get_io_service(), d_rxbuf.size(), d_tcp_no_delay);
+      tcp_connection::sptr new_connection = tcp_connection::make(static_cast<boost::asio::io_context&>(d_acceptor_tcp->get_executor().context()), d_rxbuf.size(), d_tcp_no_delay);
 
       d_acceptor_tcp->async_accept(new_connection->socket(),
         boost::bind(&socket_pdu_impl::handle_tcp_accept, this,
