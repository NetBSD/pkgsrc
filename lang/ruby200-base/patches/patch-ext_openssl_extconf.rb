$NetBSD: patch-ext_openssl_extconf.rb,v 1.1 2015/10/14 18:43:11 sevan Exp $

Check for SSLv3 support as it may nolonger be available.

--- ext/openssl/extconf.rb.orig	Sat Oct 10 17:10:39 2015
+++ ext/openssl/extconf.rb
@@ -103,6 +103,9 @@ have_func("OPENSSL_cleanse")
 have_func("SSLv2_method")
 have_func("SSLv2_server_method")
 have_func("SSLv2_client_method")
+have_func("SSLv3_method")
+have_func("SSLv3_server_method")
+have_func("SSLv3_client_method")
 have_func("TLSv1_1_method")
 have_func("TLSv1_1_server_method")
 have_func("TLSv1_1_client_method")
