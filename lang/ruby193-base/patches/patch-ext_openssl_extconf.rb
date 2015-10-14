$NetBSD: patch-ext_openssl_extconf.rb,v 1.1 2015/10/14 18:42:34 sevan Exp $

Check for SSLv3 support as it may nolonger be available

--- ext/openssl/extconf.rb.orig	Thu Oct  8 12:36:41 2015
+++ ext/openssl/extconf.rb
@@ -104,6 +104,9 @@ have_func("OPENSSL_cleanse")
 have_func("SSLv2_method")
 have_func("SSLv2_server_method")
 have_func("SSLv2_client_method")
+have_func("SSLv3_method")
+have_func("SSLv3_server_method")
+have_func("SSLv3_client_method")
 unless have_func("SSL_set_tlsext_host_name", ['openssl/ssl.h'])
   have_macro("SSL_set_tlsext_host_name", ['openssl/ssl.h']) && $defs.push("-DHAVE_SSL_SET_TLSEXT_HOST_NAME")
 end
