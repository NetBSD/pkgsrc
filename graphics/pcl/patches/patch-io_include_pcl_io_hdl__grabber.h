$NetBSD: patch-io_include_pcl_io_hdl__grabber.h,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/include/pcl/io/hdl_grabber.h.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/include/pcl/io/hdl_grabber.h
@@ -274,7 +274,7 @@ namespace pcl
       boost::asio::ip::udp::endpoint udp_listener_endpoint_;
       boost::asio::ip::address source_address_filter_;
       std::uint16_t source_port_filter_;
-      boost::asio::io_service hdl_read_socket_service_;
+      boost::asio::io_context hdl_read_socket_service_;
       boost::asio::ip::udp::socket *hdl_read_socket_;
       std::string pcap_file_name_;
       std::thread *queue_consumer_thread_;
