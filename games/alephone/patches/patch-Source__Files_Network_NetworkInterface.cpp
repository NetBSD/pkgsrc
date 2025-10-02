$NetBSD: patch-Source__Files_Network_NetworkInterface.cpp,v 1.1 2025/10/02 11:19:51 adam Exp $

Use boost::asio.

--- Source_Files/Network/NetworkInterface.cpp.orig	2025-10-02 11:04:06.613566458 +0000
+++ Source_Files/Network/NetworkInterface.cpp
@@ -18,13 +18,13 @@
 
 #include "NetworkInterface.h"
 
-IPaddress::IPaddress(const asio::ip::tcp::endpoint& endpoint)
+IPaddress::IPaddress(const boost::asio::ip::tcp::endpoint& endpoint)
 {
     _address = endpoint.address();
     set_port(endpoint.port());
 }
 
-IPaddress::IPaddress(const asio::ip::udp::endpoint& endpoint)
+IPaddress::IPaddress(const boost::asio::ip::udp::endpoint& endpoint)
 {
     _address = endpoint.address();
     set_port(endpoint.port());
@@ -49,13 +49,13 @@ void IPaddress::set_port(uint16_t port)
 
 void IPaddress::set_address(const std::string& host)
 {
-    _address = asio::ip::make_address(host);
+    _address = boost::asio::ip::make_address(host);
 }
 
 void IPaddress::set_address(const uint8_t ip[4])
 {
     std::array<unsigned char, 4> bytes = { ip[0], ip[1], ip[2], ip[3] };
-    _address = asio::ip::make_address_v4(bytes);
+    _address = boost::asio::ip::make_address_v4(bytes);
 }
 
 bool IPaddress::operator==(const IPaddress& other) const
@@ -68,29 +68,29 @@ bool IPaddress::operator!=(const IPaddre
     return !(*(this) == other);
 }
 
-UDPsocket::UDPsocket(asio::io_context& io_context, asio::ip::udp::socket&& socket) : _io_context(io_context), _socket(std::move(socket)) {}
+UDPsocket::UDPsocket(boost::asio::io_context& io_context, boost::asio::ip::udp::socket&& socket) : _io_context(io_context), _socket(std::move(socket)) {}
 
 int64_t UDPsocket::send(const UDPpacket& packet)
 {
-    asio::error_code error_code;
-    asio::ip::udp::endpoint destination(packet.address._address, packet.address.port());
-    auto result = _socket.send_to(asio::buffer(packet.buffer, packet.data_size), destination, 0, error_code);
+    boost::system::error_code error_code;
+    boost::asio::ip::udp::endpoint destination(packet.address._address, packet.address.port());
+    auto result = _socket.send_to(boost::asio::buffer(packet.buffer, packet.data_size), destination, 0, error_code);
     return error_code ? -1 : result;
 }
 
 int64_t UDPsocket::broadcast_send(const UDPpacket& packet)
 {
-    asio::error_code error_code;
-    asio::ip::udp::endpoint broadcast_endpoint(asio::ip::address_v4::broadcast(), packet.address.port());
-    auto result = _socket.send_to(asio::buffer(packet.buffer, packet.data_size), broadcast_endpoint, 0, error_code);
+    boost::system::error_code error_code;
+    boost::asio::ip::udp::endpoint broadcast_endpoint(boost::asio::ip::address_v4::broadcast(), packet.address.port());
+    auto result = _socket.send_to(boost::asio::buffer(packet.buffer, packet.data_size), broadcast_endpoint, 0, error_code);
     return error_code ? -1 : result;
 }
 
 int64_t UDPsocket::receive(UDPpacket& packet)
 {
-    asio::error_code error_code;
-    asio::ip::udp::endpoint endpoint;
-    auto result = _socket.receive_from(asio::buffer(packet.buffer), endpoint, 0, error_code);
+    boost::system::error_code error_code;
+    boost::asio::ip::udp::endpoint endpoint;
+    auto result = _socket.receive_from(boost::asio::buffer(packet.buffer), endpoint, 0, error_code);
     if (error_code) return -1;
     packet.address = endpoint;
     packet.data_size = result;
@@ -100,8 +100,8 @@ int64_t UDPsocket::receive(UDPpacket& pa
 void UDPsocket::register_receive_async(UDPpacket& packet)
 {
     _receive_async_return_value = 0;
-    _socket.async_receive_from(asio::buffer(packet.buffer), _receive_async_endpoint,
-        [&packet, this](const asio::error_code& error, std::size_t bytes_transferred) {
+    _socket.async_receive_from(boost::asio::buffer(packet.buffer), _receive_async_endpoint,
+        [&packet, this](const boost::system::error_code& error, std::size_t bytes_transferred) {
             _receive_async_return_value = error ? -1 : bytes_transferred;
             if (error) return;
             packet.data_size = bytes_transferred;
@@ -124,50 +124,50 @@ int64_t UDPsocket::check_receive() const
 
 bool UDPsocket::broadcast(bool enable)
 {
-    asio::error_code error_code;
-    _socket.set_option(asio::socket_base::broadcast(enable), error_code);
+    boost::system::error_code error_code;
+    _socket.set_option(boost::asio::socket_base::broadcast(enable), error_code);
     return !error_code;
 }
 
-TCPsocket::TCPsocket(asio::io_context& io_context, asio::ip::tcp::socket&& socket) : _io_context(io_context), _socket(std::move(socket)) {}
+TCPsocket::TCPsocket(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket&& socket) : _io_context(io_context), _socket(std::move(socket)) {}
 
 int64_t TCPsocket::send(uint8_t* buffer, size_t size)
 {
-    asio::error_code error_code;
-    auto result = _socket.send(asio::buffer(buffer, size), 0, error_code);
-    return !error_code || error_code == asio::error::would_block ? result : -1;
+    boost::system::error_code error_code;
+    auto result = _socket.send(boost::asio::buffer(buffer, size), 0, error_code);
+    return !error_code || error_code == boost::asio::error::would_block ? result : -1;
 }
 
 int64_t TCPsocket::receive(uint8_t* buffer, size_t size)
 {
-    asio::error_code error_code;
-    auto result = _socket.read_some(asio::buffer(buffer, size), error_code);
-    return !error_code || error_code == asio::error::would_block ? result : -1;
+    boost::system::error_code error_code;
+    auto result = _socket.read_some(boost::asio::buffer(buffer, size), error_code);
+    return !error_code || error_code == boost::asio::error::would_block ? result : -1;
 }
 
 bool TCPsocket::set_non_blocking(bool enable)
 {
-    asio::error_code error_code;
+    boost::system::error_code error_code;
     _socket.non_blocking(enable, error_code);
     return !error_code;
 }
 
-TCPlistener::TCPlistener(asio::io_context& io_context, const asio::ip::tcp::endpoint& endpoint) : _io_context(io_context), _socket(io_context), _acceptor(io_context, endpoint) {}
+TCPlistener::TCPlistener(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint) : _io_context(io_context), _socket(io_context), _acceptor(io_context, endpoint) {}
 
 std::unique_ptr<TCPsocket> TCPlistener::accept_connection()
 {
-    asio::error_code error_code;
+    boost::system::error_code error_code;
     _acceptor.accept(_socket, error_code);
     if (error_code) return nullptr;
 
     auto connection = std::unique_ptr<TCPsocket>(new TCPsocket(_io_context, std::move(_socket)));
-    _socket = asio::ip::tcp::socket(_io_context);
+    _socket = boost::asio::ip::tcp::socket(_io_context);
     return connection;
 }
 
 bool TCPlistener::set_non_blocking(bool enable)
 {
-    asio::error_code error_code;
+    boost::system::error_code error_code;
     _acceptor.non_blocking(enable, error_code);
     return !error_code;
 }
@@ -176,9 +176,9 @@ NetworkInterface::NetworkInterface() : _
 
 std::unique_ptr<UDPsocket> NetworkInterface::udp_open_socket(uint16_t port)
 {
-    asio::error_code error_code;
-    auto socket = asio::ip::udp::socket(_io_context);
-    auto endpoint = asio::ip::udp::endpoint(asio::ip::udp::v4(), port);
+    boost::system::error_code error_code;
+    auto socket = boost::asio::ip::udp::socket(_io_context);
+    auto endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port);
 
     socket.open(endpoint.protocol(), error_code);
     if (error_code) return nullptr;
@@ -191,22 +191,22 @@ std::unique_ptr<UDPsocket> NetworkInterf
 
 std::unique_ptr<TCPlistener> NetworkInterface::tcp_open_listener(uint16_t port)
 {
-    return std::unique_ptr<TCPlistener>(new TCPlistener(_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)));
+    return std::unique_ptr<TCPlistener>(new TCPlistener(_io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)));
 }
 
 std::unique_ptr<TCPsocket> NetworkInterface::tcp_connect_socket(const IPaddress& address)
 {
-    auto socket = asio::ip::tcp::socket(_io_context);
-    asio::error_code error_code;
-    socket.connect(asio::ip::tcp::endpoint(address._address, address.port()), error_code);
+    auto socket = boost::asio::ip::tcp::socket(_io_context);
+    boost::system::error_code error_code;
+    socket.connect(boost::asio::ip::tcp::endpoint(address._address, address.port()), error_code);
     if (error_code) return nullptr;
     return std::unique_ptr<TCPsocket>(new TCPsocket(_io_context, std::move(socket)));
 }
 
 std::optional<IPaddress> NetworkInterface::resolve_address(const std::string& host, uint16_t port)
 {
-    asio::error_code error_code;
-    asio::ip::tcp::resolver::results_type endpoints = _resolver.resolve(host, std::to_string(port), error_code);
+    boost::system::error_code error_code;
+    boost::asio::ip::tcp::resolver::results_type endpoints = _resolver.resolve(host, std::to_string(port), error_code);
     if (error_code) return std::nullopt;
 
     for (const auto& endpoint : endpoints)
@@ -218,4 +218,4 @@ std::optional<IPaddress> NetworkInterfac
     }
 
     return std::nullopt;
-}
\ No newline at end of file
+}
