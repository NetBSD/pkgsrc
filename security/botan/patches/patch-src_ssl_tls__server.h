$NetBSD: patch-src_ssl_tls__server.h,v 1.1 2016/05/31 21:36:17 joerg Exp $

--- src/ssl/tls_server.h.orig	2016-05-25 20:42:12.789110157 +0000
+++ src/ssl/tls_server.h
@@ -36,8 +36,8 @@ class BOTAN_DLL TLS_Server : public TLS_
       * FIXME: support cert chains (!)
       * FIXME: support anonymous servers
       */
-      TLS_Server(std::tr1::function<size_t (byte[], size_t)> input_fn,
-                 std::tr1::function<void (const byte[], size_t)> output_fn,
+      TLS_Server(function<size_t (byte[], size_t)> input_fn,
+                 function<void (const byte[], size_t)> output_fn,
                  const TLS_Policy& policy,
                  RandomNumberGenerator& rng,
                  const X509_Certificate& cert,
@@ -53,7 +53,7 @@ class BOTAN_DLL TLS_Server : public TLS_
 
       void process_handshake_msg(Handshake_Type, const MemoryRegion<byte>&);
 
-      std::tr1::function<size_t (byte[], size_t)> input_fn;
+      function<size_t (byte[], size_t)> input_fn;
 
       const TLS_Policy& policy;
       RandomNumberGenerator& rng;
