$NetBSD: patch-t_local_43__misc__functions.t,v 1.1 2021/10/16 14:02:56 schmonz Exp $

Patch taken from OpenBSD ports:

LibreSSL uses different names for TLS 1.3 ciphers.

LibreSSL does not define TLS1_3_VERSION, but test discovers TLS 1.3.

--- t/local/43_misc_functions.t.orig	Thu Jan 21 15:14:11 2021
+++ t/local/43_misc_functions.t
@@ -40,6 +40,10 @@ our %tls_1_3_aead_cipher_to_keyblock_size = (
      'TLS_AES_128_GCM_SHA256' => 56,
      'TLS_AES_256_GCM_SHA384' => 88,
      'TLS_CHACHA20_POLY1305_SHA256' => 88,
+     # LibreSSL uses different names
+     'AEAD-AES128-GCM-SHA256' => 56,
+     'AEAD-AES256-GCM-SHA384' => 88,
+     'AEAD-CHACHA20-POLY1305-SHA256' => 88,
     );
 
 # Combine the AEAD hashes
@@ -56,6 +60,11 @@ our %version_str2int =
      'TLSv1.2' => sub {return eval {Net::SSLeay::TLS1_2_VERSION();}},
      'TLSv1.3' => sub {return eval {Net::SSLeay::TLS1_3_VERSION();}},
     );
+
+# LibreSSL does not define TLS1_3_VERSION
+if (Net::SSLeay::constant("LIBRESSL_VERSION_NUMBER")) {
+    $version_str2int{'TLSv1.3'} = sub {return 0x0304};
+}
 
 # Tests that don't need a connection
 client_test_ciphersuites();
