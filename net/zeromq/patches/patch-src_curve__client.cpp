$NetBSD: patch-src_curve__client.cpp,v 1.1 2015/11/24 11:01:34 wiz Exp $

Problem: return code of sodium_init() is not checked.

There are two todo comments in curve_client.cpp and curve_server.cpp that suggest
checking the return code of sodium_init() call. sodium_init() returns -1 on error,
0 on success and 1 if it has been called before and is already initalized:
https://github.com/jedisct1/libsodium/blob/master/src/libsodium/sodium/core.c

https://github.com/zeromq/zeromq4-1/commit/89d4e995ef92d5cb3d0f0373ec7d80c2ad7fa0d3

--- src/curve_client.cpp.orig	2015-06-15 09:43:08.000000000 +0000
+++ src/curve_client.cpp
@@ -48,6 +48,7 @@ zmq::curve_client_t::curve_client_t (con
     cn_peer_nonce(1),
     sync()
 {
+    int rc;
     memcpy (public_key, options_.curve_public_key, crypto_box_PUBLICKEYBYTES);
     memcpy (secret_key, options_.curve_secret_key, crypto_box_SECRETKEYBYTES);
     memcpy (server_key, options_.curve_server_key, crypto_box_PUBLICKEYBYTES);
@@ -57,12 +58,12 @@ zmq::curve_client_t::curve_client_t (con
     unsigned char tmpbytes[4];
     randombytes(tmpbytes, 4);
 #else
-    // todo check return code
-    sodium_init();
+    rc = sodium_init ();
+    zmq_assert (rc != -1);
 #endif
 
     //  Generate short-term key pair
-    const int rc = crypto_box_keypair (cn_public, cn_secret);
+    rc = crypto_box_keypair (cn_public, cn_secret);
     zmq_assert (rc == 0);
 }
 
