$NetBSD: patch-Source__Files_Network_NetworkInterface.h,v 1.1 2025/10/02 11:19:51 adam Exp $

Use boost::asio.

--- Source_Files/Network/NetworkInterface.h.orig	2025-10-02 10:58:39.161085374 +0000
+++ Source_Files/Network/NetworkInterface.h
@@ -19,7 +19,7 @@
 #ifndef NETWORK_INTERFACE_H
 #define NETWORK_INTERFACE_H
 
-#include <asio.hpp>
+#include <boost/asio.hpp>
 #include <string>
 #include <optional>
 
@@ -29,11 +29,11 @@ private:
     friend class UDPsocket;
     friend class TCPsocket;
 
-    asio::ip::address _address;
+    boost::asio::ip::address _address;
     uint16_t _port = 0;
 
-    IPaddress(const asio::ip::tcp::endpoint& endpoint);
-    IPaddress(const asio::ip::udp::endpoint& endpoint);
+    IPaddress(const boost::asio::ip::tcp::endpoint& endpoint);
+    IPaddress(const boost::asio::ip::udp::endpoint& endpoint);
 
 public:
     IPaddress(const std::string& host, uint16_t port);
@@ -66,11 +66,11 @@ struct UDPpacket
 
 class UDPsocket {
 private:
-    asio::io_context& _io_context;
-    asio::ip::udp::socket _socket;
-    asio::ip::udp::endpoint _receive_async_endpoint;
+    boost::asio::io_context& _io_context;
+    boost::asio::ip::udp::socket _socket;
+    boost::asio::ip::udp::endpoint _receive_async_endpoint;
     int64_t _receive_async_return_value = 0;
-    UDPsocket(asio::io_context& io_context, asio::ip::udp::socket&& socket);
+    UDPsocket(boost::asio::io_context& io_context, boost::asio::ip::udp::socket&& socket);
     friend class NetworkInterface;
 public:
     int64_t broadcast_send(const UDPpacket& packet);
@@ -84,9 +84,9 @@ public:
 
 class TCPsocket {
 private:
-    asio::io_context& _io_context;
-    asio::ip::tcp::socket _socket;
-    TCPsocket(asio::io_context& io_context, asio::ip::tcp::socket&& socket);
+    boost::asio::io_context& _io_context;
+    boost::asio::ip::tcp::socket _socket;
+    TCPsocket(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket&& socket);
     friend class NetworkInterface;
     friend class TCPlistener;
 public:
@@ -98,10 +98,10 @@ public:
 
 class TCPlistener {
 private:
-    asio::io_context& _io_context;
-    asio::ip::tcp::acceptor _acceptor;
-    asio::ip::tcp::socket _socket;
-    TCPlistener(asio::io_context& io_context, const asio::ip::tcp::endpoint& endpoint);
+    boost::asio::io_context& _io_context;
+    boost::asio::ip::tcp::acceptor _acceptor;
+    boost::asio::ip::tcp::socket _socket;
+    TCPlistener(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint);
     friend class NetworkInterface;
 public:
     std::unique_ptr<TCPsocket> accept_connection();
@@ -110,8 +110,8 @@ public:
 
 class NetworkInterface {
 private:
-    asio::io_context _io_context;
-    asio::ip::tcp::resolver _resolver;
+    boost::asio::io_context _io_context;
+    boost::asio::ip::tcp::resolver _resolver;
 public:
     NetworkInterface();
     std::unique_ptr<UDPsocket> udp_open_socket(uint16_t port);
