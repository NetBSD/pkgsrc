$NetBSD: patch-src_ssl_tls__server.cpp,v 1.1 2016/05/31 21:36:17 joerg Exp $

--- src/ssl/tls_server.cpp.orig	2016-05-25 20:43:18.345421693 +0000
+++ src/ssl/tls_server.cpp
@@ -85,8 +85,8 @@ void server_check_state(Handshake_Type n
 /*
 * TLS Server Constructor
 */
-TLS_Server::TLS_Server(std::tr1::function<size_t (byte[], size_t)> input_fn,
-                       std::tr1::function<void (const byte[], size_t)> output_fn,
+TLS_Server::TLS_Server(function<size_t (byte[], size_t)> input_fn,
+                       function<void (const byte[], size_t)> output_fn,
                        const TLS_Policy& policy,
                        RandomNumberGenerator& rng,
                        const X509_Certificate& cert,
