$NetBSD: patch-src_security_tls_polyorb-tls.adb,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix deprecated functions

--- src/security/tls/polyorb-tls.adb.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/security/tls/polyorb-tls.adb
@@ -223,9 +223,10 @@
 
       --  Library initialization
 
-      procedure SSL_library_init;
-
-      procedure SSL_load_error_strings;
+      function OPENSSL_init_ssl
+        (Opts    : Interfaces.C.unsigned_long_long;
+        settings : INIT_SETTINGS_ACCESS)
+        return Interfaces.C.int;
 
       --  PolyORB extensions
 
@@ -270,9 +271,8 @@
       pragma Import (C, SSL_get_cipher_list,      "SSL_get_cipher_list");
       pragma Import (C, SSL_get_ciphers,          "SSL_get_ciphers");
       pragma Import (C, SSL_get_fd,               "SSL_get_fd");
-      pragma Import (C, SSL_get_peer_certificate, "SSL_get_peer_certificate");
-      pragma Import (C, SSL_library_init,         "SSL_library_init");
-      pragma Import (C, SSL_load_error_strings,   "SSL_load_error_strings");
+      pragma Import (C, SSL_get_peer_certificate, "SSL_get1_peer_certificate");
+      pragma Import (C, OPENSSL_init_ssl,         "OPENSSL_init_ssl");
       pragma Import (C, SSL_new,                  "SSL_new");
       pragma Import (C, SSL_pending,              "SSL_pending");
       pragma Import (C, SSL_read,                 "SSL_read");
@@ -549,9 +549,11 @@
    ----------------
 
    procedure Initialize is
+      Result : Interfaces.C.int := Thin.OPENSSL_init_ssl (0, null);
    begin
-      Thin.SSL_load_error_strings;
-      Thin.SSL_library_init;
+      if Result = 0 then
+         null;
+      end if;
       --  XXX actions_to_seed_PRNG
    end Initialize;
 
