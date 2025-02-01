$NetBSD: patch-src_cli_tls__http__server.cpp,v 1.1 2025/02/01 22:01:38 he Exp $

Adapt to newer boost.

--- src/cli/tls_http_server.cpp.orig	2025-01-29 14:06:52.004694953 +0000
+++ src/cli/tls_http_server.cpp
@@ -176,7 +176,7 @@ class TLS_Asio_HTTP_Session final : publ
       typedef std::shared_ptr<TLS_Asio_HTTP_Session> pointer;
 
       static pointer create(
-         boost::asio::io_service& io,
+         boost::asio::io_context& io,
          Botan::TLS::Session_Manager& session_manager,
          Botan::Credentials_Manager& credentials,
          Botan::TLS::Policy& policy)
@@ -201,7 +201,7 @@ class TLS_Asio_HTTP_Session final : publ
          }
 
    private:
-      TLS_Asio_HTTP_Session(boost::asio::io_service& io,
+      TLS_Asio_HTTP_Session(boost::asio::io_context& io,
                             Botan::TLS::Session_Manager& session_manager,
                             Botan::Credentials_Manager& credentials,
                             Botan::TLS::Policy& policy)
@@ -406,7 +406,7 @@ class TLS_Asio_HTTP_Session final : publ
             }
          }
 
-      boost::asio::io_service::strand m_strand;
+      boost::asio::io_context::strand m_strand;
 
       tcp::socket m_client_socket;
 
@@ -427,7 +427,7 @@ class TLS_Asio_HTTP_Server final
       typedef TLS_Asio_HTTP_Session session;
 
       TLS_Asio_HTTP_Server(
-         boost::asio::io_service& io, unsigned short port,
+         boost::asio::io_context& io, unsigned short port,
          Botan::Credentials_Manager& creds,
          Botan::TLS::Policy& policy,
          Botan::TLS::Session_Manager& session_mgr,
@@ -551,7 +551,7 @@ class TLS_HTTP_Server final : public Com
             session_mgr.reset(new Botan::TLS::Session_Manager_In_Memory(rng()));
             }
 
-         boost::asio::io_service io;
+         boost::asio::io_context io;
 
          TLS_Asio_HTTP_Server server(io, listen_port, creds, *policy, *session_mgr, max_clients);
 
