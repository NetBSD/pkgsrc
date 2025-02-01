$NetBSD: patch-src_cli_tls__proxy.cpp,v 1.1 2025/02/01 22:01:38 he Exp $

Adapt patch from botan3, originally from

https://github.com/randombit/botan/commit/2a406beab449a2cb310fa543451a7087ca7b4b1a

--- src/cli/tls_proxy.cpp.orig	2025-01-23 11:05:38.438228429 +0000
+++ src/cli/tls_proxy.cpp
@@ -98,11 +98,11 @@ class tls_proxy_session final : public s
       typedef std::shared_ptr<tls_proxy_session> pointer;
 
       static pointer create(
-         boost::asio::io_service& io,
+         boost::asio::io_context& io,
          Botan::TLS::Session_Manager& session_manager,
          Botan::Credentials_Manager& credentials,
          Botan::TLS::Policy& policy,
-         tcp::resolver::iterator endpoints)
+         tcp::resolver::results_type endpoints)
          {
          return pointer(
                    new tls_proxy_session(
@@ -141,11 +141,11 @@ class tls_proxy_session final : public s
 
    private:
       tls_proxy_session(
-         boost::asio::io_service& io,
+         boost::asio::io_context& io,
          Botan::TLS::Session_Manager& session_manager,
          Botan::Credentials_Manager& credentials,
          Botan::TLS::Policy& policy,
-         tcp::resolver::iterator endpoints)
+         tcp::resolver::results_type endpoints)
          : m_strand(io)
          , m_server_endpoints(endpoints)
          , m_client_socket(io)
@@ -318,7 +318,7 @@ class tls_proxy_session final : public s
          {
          m_hostname = session.server_info().hostname();
 
-         auto onConnect = [this](boost::system::error_code ec, tcp::resolver::iterator /*endpoint*/)
+         auto onConnect = [this](boost::system::error_code ec, tcp::resolver::results_type::iterator /*endpoint*/)
             {
             if(ec)
                {
@@ -328,7 +328,7 @@ class tls_proxy_session final : public s
             server_read(boost::system::error_code(), 0); // start read loop
             proxy_write_to_server(nullptr, 0);
             };
-         async_connect(m_server_socket, m_server_endpoints, onConnect);
+         async_connect(m_server_socket, m_server_endpoints.begin(), m_server_endpoints.end(), onConnect);
          return true;
          }
 
@@ -341,9 +341,9 @@ class tls_proxy_session final : public s
             }
          }
 
-      boost::asio::io_service::strand m_strand;
+      boost::asio::io_context::strand m_strand;
 
-      tcp::resolver::iterator m_server_endpoints;
+      tcp::resolver::results_type m_server_endpoints;
 
       tcp::socket m_client_socket;
       tcp::socket m_server_socket;
@@ -369,8 +369,8 @@ class tls_proxy_server final
       typedef tls_proxy_session session;
 
       tls_proxy_server(
-         boost::asio::io_service& io, unsigned short port,
-         tcp::resolver::iterator endpoints,
+         boost::asio::io_context& io, unsigned short port,
+         tcp::resolver::results_type endpoints,
          Botan::Credentials_Manager& creds,
          Botan::TLS::Policy& policy,
          Botan::TLS::Session_Manager& session_mgr,
@@ -428,7 +428,7 @@ class tls_proxy_server final
          }
 
       tcp::acceptor m_acceptor;
-      tcp::resolver::iterator m_server_endpoints;
+      tcp::resolver::results_type m_server_endpoints;
 
       Botan::Credentials_Manager& m_creds;
       Botan::TLS::Policy& m_policy;
@@ -479,10 +479,10 @@ class TLS_Proxy final : public Command
 
          auto policy = load_tls_policy(get_arg("policy"));
 
-         boost::asio::io_service io;
+         boost::asio::io_context io;
 
          tcp::resolver resolver(io);
-         auto server_endpoint_iterator = resolver.resolve({ target, target_port });
+         auto server_endpoint_iterator = resolver.resolve(target, target_port);
 
          std::unique_ptr<Botan::TLS::Session_Manager> session_mgr;
 
