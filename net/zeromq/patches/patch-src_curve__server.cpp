$NetBSD: patch-src_curve__server.cpp,v 1.1 2015/11/24 11:01:34 wiz Exp $

Problem: return code of sodium_init() is not checked.

There are two todo comments in curve_client.cpp and curve_server.cpp that suggest
checking the return code of sodium_init() call. sodium_init() returns -1 on error,
0 on success and 1 if it has been called before and is already initalized:
https://github.com/jedisct1/libsodium/blob/master/src/libsodium/sodium/core.c

https://github.com/zeromq/zeromq4-1/commit/89d4e995ef92d5cb3d0f0373ec7d80c2ad7fa0d3

--- src/curve_server.cpp.orig	2015-06-15 09:43:08.000000000 +0000
+++ src/curve_server.cpp
@@ -52,6 +52,7 @@ zmq::curve_server_t::curve_server_t (ses
     cn_peer_nonce(1),
     sync()
 {
+    int rc;
     //  Fetch our secret key from socket options
     memcpy (secret_key, options_.curve_secret_key, crypto_box_SECRETKEYBYTES);
     scoped_lock_t lock (sync);
@@ -60,12 +61,12 @@ zmq::curve_server_t::curve_server_t (ses
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
 
