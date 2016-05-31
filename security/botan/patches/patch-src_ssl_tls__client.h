$NetBSD: patch-src_ssl_tls__client.h,v 1.1 2016/05/31 21:36:17 joerg Exp $

--- src/ssl/tls_client.h.orig	2016-05-25 20:42:17.404292837 +0000
+++ src/ssl/tls_client.h
@@ -33,8 +33,8 @@ class BOTAN_DLL TLS_Client : public TLS_
       void add_client_cert(const X509_Certificate& cert,
                            Private_Key* cert_key);
 
-      TLS_Client(std::tr1::function<size_t (byte[], size_t)> input_fn,
-                 std::tr1::function<void (const byte[], size_t)> output_fn,
+      TLS_Client(function<size_t (byte[], size_t)> input_fn,
+                 function<void (const byte[], size_t)> output_fn,
                  const TLS_Policy& policy,
                  RandomNumberGenerator& rng);
 
@@ -51,7 +51,7 @@ class BOTAN_DLL TLS_Client : public TLS_
       void read_handshake(byte, const MemoryRegion<byte>&);
       void process_handshake_msg(Handshake_Type, const MemoryRegion<byte>&);
 
-      std::tr1::function<size_t (byte[], size_t)> input_fn;
+      function<size_t (byte[], size_t)> input_fn;
 
       const TLS_Policy& policy;
       RandomNumberGenerator& rng;
