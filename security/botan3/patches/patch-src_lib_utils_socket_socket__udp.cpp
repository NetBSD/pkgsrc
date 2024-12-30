$NetBSD: patch-src_lib_utils_socket_socket__udp.cpp,v 1.1 2024/12/30 09:40:20 wiz Exp $

https://github.com/randombit/botan/commit/2a406beab449a2cb310fa543451a7087ca7b4b1a

--- src/lib/utils/socket/socket_udp.cpp.orig	2024-10-26 07:00:10.000000000 +0000
+++ src/lib/utils/socket/socket_udp.cpp
@@ -46,20 +46,19 @@ class Asio_SocketUDP final : public OS::
    public:
       Asio_SocketUDP(std::string_view hostname, std::string_view service, std::chrono::microseconds timeout) :
             m_timeout(timeout), m_timer(m_io), m_udp(m_io) {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
          check_timeout();
 
          boost::asio::ip::udp::resolver resolver(m_io);
-         boost::asio::ip::udp::resolver::query query(std::string{hostname}, std::string{service});
-         boost::asio::ip::udp::resolver::iterator dns_iter = resolver.resolve(query);
+         boost::asio::ip::udp::resolver::results_type dns_iter = resolver.resolve(std::string{hostname}, std::string{service});
 
          boost::system::error_code ec = boost::asio::error::would_block;
 
-         auto connect_cb = [&ec](const boost::system::error_code& e, const boost::asio::ip::udp::resolver::iterator&) {
+         auto connect_cb = [&ec](const boost::system::error_code& e, boost::asio::ip::udp::resolver::results_type::iterator) {
             ec = e;
          };
 
-         boost::asio::async_connect(m_udp, dns_iter, connect_cb);
+         boost::asio::async_connect(m_udp, dns_iter.begin(), dns_iter.end(), connect_cb);
 
          while(ec == boost::asio::error::would_block) {
             m_io.run_one();
@@ -74,7 +73,7 @@ class Asio_SocketUDP final : public OS::
       }
 
       void write(const uint8_t buf[], size_t len) override {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
 
          boost::system::error_code ec = boost::asio::error::would_block;
 
@@ -90,7 +89,7 @@ class Asio_SocketUDP final : public OS::
       }
 
       size_t read(uint8_t buf[], size_t len) override {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
 
          boost::system::error_code ec = boost::asio::error::would_block;
          size_t got = 0;
@@ -116,7 +115,7 @@ class Asio_SocketUDP final : public OS::
 
    private:
       void check_timeout() {
-         if(m_udp.is_open() && m_timer.expires_at() < std::chrono::system_clock::now()) {
+         if(m_udp.is_open() && m_timer.expiry() < std::chrono::system_clock::now()) {
             boost::system::error_code err;
 
             // NOLINTNEXTLINE(bugprone-unused-return-value,cert-err33-c)
@@ -127,7 +126,7 @@ class Asio_SocketUDP final : public OS::
       }
 
       const std::chrono::microseconds m_timeout;
-      boost::asio::io_service m_io;
+      boost::asio::io_context m_io;
       boost::asio::system_timer m_timer;
       boost::asio::ip::udp::socket m_udp;
 };
