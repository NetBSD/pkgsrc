$NetBSD: patch-spamc_libspamc.c,v 1.3 2022/12/17 14:29:33 gdt Exp $

Set the client protocol to TLS instead of SSLv3.
Fixes build with current openssl.

--- spamc/libspamc.c.orig	2022-12-06 23:27:29.000000000 +0000
+++ spamc/libspamc.c
@@ -636,7 +636,7 @@ static SSL_CTX * _try_ssl_ctx_init(int f
     SSLeay_add_ssl_algorithms();
     SSL_load_error_strings();
     /* this method allows negotiation of version */
-    meth = SSLv23_client_method();
+    meth = TLSv1_client_method();
     ctx = SSL_CTX_new(meth);
     if (ctx == NULL) {
         libspamc_log(flags, LOG_ERR, "cannot create SSL CTX context: %s",
