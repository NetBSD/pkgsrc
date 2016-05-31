$NetBSD: patch-src_ssl_tls__client.cpp,v 1.1 2016/05/31 21:36:17 joerg Exp $

--- src/ssl/tls_client.cpp.orig	2016-05-25 20:42:19.378772780 +0000
+++ src/ssl/tls_client.cpp
@@ -81,8 +81,8 @@ void client_check_state(Handshake_Type n
 /**
 * TLS Client Constructor
 */
-TLS_Client::TLS_Client(std::tr1::function<size_t (byte[], size_t)> input_fn,
-                       std::tr1::function<void (const byte[], size_t)> output_fn,
+TLS_Client::TLS_Client(function<size_t (byte[], size_t)> input_fn,
+                       function<void (const byte[], size_t)> output_fn,
                        const TLS_Policy& policy,
                        RandomNumberGenerator& rng) :
    input_fn(input_fn),
