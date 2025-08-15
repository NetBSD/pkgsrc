$NetBSD: patch-src_ssl_polyorb-ssl.adb,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix old library usage

--- src/ssl/polyorb-ssl.adb.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/ssl/polyorb-ssl.adb
@@ -74,9 +74,10 @@
 
       --  General initialization subprograms
 
-      procedure SSL_library_init;
-
-      procedure SSL_load_error_strings;
+      function OPENSSL_init_ssl
+        (Opts    : Interfaces.C.unsigned_long_long;
+        settings : INIT_SETTINGS_ACCESS)
+        return Interfaces.C.int;
 
       --  Context subprograms
 
@@ -254,8 +255,7 @@
       pragma Import (C, SSL_free, "SSL_free");
       pragma Import (C, SSL_get_fd, "SSL_get_fd");
       pragma Import (C, SSL_get_ciphers, "SSL_get_ciphers");
-      pragma Import (C, SSL_library_init, "SSL_library_init");
-      pragma Import (C, SSL_load_error_strings, "SSL_load_error_strings");
+      pragma Import (C, OPENSSL_init_ssl, "OPENSSL_init_ssl");
       pragma Import (C, SSL_load_client_CA_file, "SSL_load_client_CA_file");
       pragma Import (C, SSL_new, "SSL_new");
       pragma Import (C, SSL_pending, "SSL_pending");
@@ -609,9 +609,11 @@
    ----------------
 
    procedure Initialize is
+      Result : Interfaces.C.int := Thin.OPENSSL_init_ssl (0, null);
    begin
-      Thin.SSL_load_error_strings;
-      Thin.SSL_library_init;
+      if Result = 0 then
+        null;
+      end if;
       --  XXX actions_to_seed_PRNG
    end Initialize;
 
