$NetBSD: patch-vio_viossl.c,v 1.2 2013/12/03 20:02:42 adam Exp $

Compatibility fix.

--- vio/viossl.c.orig	2013-04-05 12:27:17.000000000 +0000
+++ vio/viossl.c
@@ -391,7 +391,7 @@ static int ssl_do(struct st_VioSSLFd *pt
   SSL_clear(ssl);
   SSL_SESSION_set_timeout(SSL_get_session(ssl), timeout);
   SSL_set_fd(ssl, sd);
-#ifndef HAVE_YASSL
+#if !defined(HAVE_YASSL) && defined(SSL_OP_NO_COMPRESSION)
   SSL_set_options(ssl, SSL_OP_NO_COMPRESSION);
 #endif
 
