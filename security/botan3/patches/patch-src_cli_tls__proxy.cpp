$NetBSD: patch-src_cli_tls__proxy.cpp,v 1.1 2024/12/30 09:40:20 wiz Exp $

https://github.com/randombit/botan/commit/2a406beab449a2cb310fa543451a7087ca7b4b1a

--- src/cli/tls_proxy.cpp.orig	2024-10-26 07:00:10.000000000 +0000
+++ src/cli/tls_proxy.cpp
@@ -106,11 +106,11 @@ class tls_proxy_session final : public s
 
       typedef std::shared_ptr<tls_proxy_session> pointer;
 
-      static pointer create(boost::asio::io_service& io,
+      static pointer create(boost::asio::io_context& io,
                             const std::shared_ptr<Botan::TLS::Session_Manager>& session_manager,
                             const std::shared_ptr<Botan::Credentials_Manager>& credentials,
                             const std::shared_ptr<Botan::TLS::Policy>& policy,
-                            const tcp::resolver::iterator& endpoints) {
+                            const tcp::resolver::results_type& endpoints) {
          auto session = std::make_shared<tls_proxy_session>(io, endpoints);
 
          // Defer the setup of the TLS server to make use of
@@ -144,7 +144,7 @@ class tls_proxy_session final : public s
          }
       }
 
-      tls_proxy_session(boost::asio::io_service& io, tcp::resolver::iterator endpoints) :
+      tls_proxy_session(boost::asio::io_context& io, tcp::resolver::results_type endpoints) :
             m_strand(io),
             m_server_endpoints(std::move(endpoints)),
             m_client_socket(io),
@@ -287,7 +287,7 @@ class tls_proxy_session final : public s
 
       void tls_session_activated() override {
          auto onConnect = [self = weak_from_this()](boost::system::error_code ec,
-                                                    const tcp::resolver::iterator& /*endpoint*/) {
+                                                    tcp::resolver::results_type::iterator /*endpoint*/) {
             if(ec) {
                log_error("Server connection", ec);
                return;
@@ -301,7 +301,7 @@ class tls_proxy_session final : public s
                return;
             }
          };
-         async_connect(m_server_socket, m_server_endpoints, onConnect);
+         async_connect(m_server_socket, m_server_endpoints.begin(), m_server_endpoints.end(), onConnect);
       }
 
       void tls_session_established(const Botan::TLS::Session_Summary& session) override {
@@ -315,9 +315,9 @@ class tls_proxy_session final : public s
          }
       }
 
-      boost::asio::io_service::strand m_strand;
+      boost::asio::io_context::strand m_strand;
 
-      tcp::resolver::iterator m_server_endpoints;
+      tcp::resolver::results_type m_server_endpoints;
 
       tcp::socket m_client_socket;
       tcp::socket m_server_socket;
@@ -341,9 +341,9 @@ class tls_proxy_server final {
    public:
       typedef tls_proxy_session session;
 
-      tls_proxy_server(boost::asio::io_service& io,
+      tls_proxy_server(boost::asio::io_context& io,
                        unsigned short port,
-                       tcp::resolver::iterator endpoints,
+                       tcp::resolver::results_type endpoints,
                        std::shared_ptr<Botan::Credentials_Manager> creds,
                        std::shared_ptr<Botan::TLS::Policy> policy,
                        std::shared_ptr<Botan::TLS::Session_Manager> session_mgr,
@@ -383,7 +383,7 @@ class tls_proxy_server final {
       }
 
       tcp::acceptor m_acceptor;
-      tcp::resolver::iterator m_server_endpoints;
+      tcp::resolver::results_type m_server_endpoints;
 
       std::shared_ptr<Botan::Credentials_Manager> m_creds;
       std::shared_ptr<Botan::TLS::Policy> m_policy;
@@ -429,10 +429,10 @@ class TLS_Proxy final : public Command {
 
          auto policy = load_tls_policy(get_arg("policy"));
 
-         boost::asio::io_service io;
+         boost::asio::io_context io;
 
          tcp::resolver resolver(io);
-         auto server_endpoint_iterator = resolver.resolve({target, target_port});
+         auto server_endpoint_iterator = resolver.resolve(target, target_port);
 
          std::shared_ptr<Botan::TLS::Session_Manager> session_mgr;
 
