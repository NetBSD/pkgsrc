$NetBSD: patch-src_lib_utils_socket_socket.cpp,v 1.1 2025/02/01 22:01:38 he Exp $

Adapt patch from botan3 to work with newer boost, originally from

https://github.com/randombit/botan/commit/2a406beab449a2cb310fa543451a7087ca7b4b1a

--- src/lib/utils/socket/socket.cpp.orig	2025-01-23 11:13:43.055705480 +0000
+++ src/lib/utils/socket/socket.cpp
@@ -48,19 +48,18 @@ class Asio_Socket final : public OS::Soc
                   std::chrono::milliseconds timeout) :
          m_timeout(timeout), m_timer(m_io), m_tcp(m_io)
          {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
          check_timeout();
 
          boost::asio::ip::tcp::resolver resolver(m_io);
-         boost::asio::ip::tcp::resolver::query query(hostname, service);
-         boost::asio::ip::tcp::resolver::iterator dns_iter = resolver.resolve(query);
+         boost::asio::ip::tcp::resolver::results_type dns_iter = resolver.resolve(std::string{hostname}, std::string{service});
 
          boost::system::error_code ec = boost::asio::error::would_block;
 
          auto connect_cb = [&ec](const boost::system::error_code& e,
-                                 boost::asio::ip::tcp::resolver::iterator) { ec = e; };
+                                 boost::asio::ip::tcp::resolver::results_type::iterator) { ec = e; };
 
-         boost::asio::async_connect(m_tcp, dns_iter, connect_cb);
+         boost::asio::async_connect(m_tcp, dns_iter.begin(), dns_iter.end(), connect_cb);
 
          while(ec == boost::asio::error::would_block)
             {
@@ -75,7 +74,7 @@ class Asio_Socket final : public OS::Soc
 
       void write(const uint8_t buf[], size_t len) override
          {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
 
          boost::system::error_code ec = boost::asio::error::would_block;
 
@@ -92,7 +91,7 @@ class Asio_Socket final : public OS::Soc
 
       size_t read(uint8_t buf[], size_t len) override
          {
-         m_timer.expires_from_now(m_timeout);
+         m_timer.expires_after(m_timeout);
 
          boost::system::error_code ec = boost::asio::error::would_block;
          size_t got = 0;
@@ -115,7 +114,7 @@ class Asio_Socket final : public OS::Soc
    private:
       void check_timeout()
          {
-         if(m_tcp.is_open() && m_timer.expires_at() < std::chrono::system_clock::now())
+         if(m_tcp.is_open() && m_timer.expiry() < std::chrono::system_clock::now())
             {
             boost::system::error_code err;
             m_tcp.close(err);
@@ -125,7 +124,7 @@ class Asio_Socket final : public OS::Soc
          }
 
       const std::chrono::milliseconds m_timeout;
-      boost::asio::io_service m_io;
+      boost::asio::io_context m_io;
       boost::asio::system_timer m_timer;
       boost::asio::ip::tcp::socket m_tcp;
    };
