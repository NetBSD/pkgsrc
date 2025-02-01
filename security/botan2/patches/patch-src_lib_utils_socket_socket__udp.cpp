$NetBSD: patch-src_lib_utils_socket_socket__udp.cpp,v 1.1 2025/02/01 22:01:38 he Exp $

Adapt patch from botan3 to work with newer boost.  Original from

https://github.com/randombit/botan/commit/2a406beab449a2cb310fa543451a7087ca7b4b1a

--- src/lib/utils/socket/socket_udp.cpp.orig	2025-01-23 11:19:22.203504617 +0000
+++ src/lib/utils/socket/socket_udp.cpp
@@ -48,19 +48,18 @@ class Asio_SocketUDP final : public OS::
                      std::chrono::microseconds timeout) :
          m_timeout(timeout), m_timer(m_io), m_udp(m_io)
          {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
          check_timeout();
 
          boost::asio::ip::udp::resolver resolver(m_io);
-         boost::asio::ip::udp::resolver::query query(hostname, service);
-         boost::asio::ip::udp::resolver::iterator dns_iter = resolver.resolve(query);
+         boost::asio::ip::udp::resolver::results_type dns_iter = resolver.resolve(std::string{hostname}, std::string{service});
 
          boost::system::error_code ec = boost::asio::error::would_block;
 
          auto connect_cb = [&ec](const boost::system::error_code& e,
-         boost::asio::ip::udp::resolver::iterator) { ec = e; };
+         boost::asio::ip::udp::resolver::results_type::iterator) { ec = e; };
 
-         boost::asio::async_connect(m_udp, dns_iter, connect_cb);
+         boost::asio::async_connect(m_udp, dns_iter.begin(), dns_iter.end(), connect_cb);
 
          while(ec == boost::asio::error::would_block)
             {
@@ -75,7 +74,7 @@ class Asio_SocketUDP final : public OS::
 
       void write(const uint8_t buf[], size_t len) override
          {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
 
          boost::system::error_code ec = boost::asio::error::would_block;
 
@@ -95,7 +94,7 @@ class Asio_SocketUDP final : public OS::
 
       size_t read(uint8_t buf[], size_t len) override
          {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
 
          boost::system::error_code ec = boost::asio::error::would_block;
          size_t got = 0;
@@ -121,7 +120,7 @@ class Asio_SocketUDP final : public OS::
    private:
       void check_timeout()
          {
-         if(m_udp.is_open() && m_timer.expires_at() < std::chrono::system_clock::now())
+         if(m_udp.is_open() && m_timer.expiry() < std::chrono::system_clock::now())
             {
             boost::system::error_code err;
             m_udp.close(err);
@@ -131,7 +130,7 @@ class Asio_SocketUDP final : public OS::
          }
 
       const std::chrono::microseconds m_timeout;
-      boost::asio::io_service m_io;
+      boost::asio::io_context m_io;
       boost::asio::system_timer m_timer;
       boost::asio::ip::udp::socket m_udp;
    };
