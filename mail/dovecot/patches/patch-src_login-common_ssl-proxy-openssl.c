$NetBSD: patch-src_login-common_ssl-proxy-openssl.c,v 1.1 2015/01/23 12:17:47 wiz Exp $

Fix for CVE-2014-3430.
Based on http://hg.dovecot.org/dovecot-1.2/raw-rev/8ba4253adc9b

--- src/login-common/ssl-proxy-openssl.c.orig	2011-01-20 21:16:59.000000000 +0000
+++ src/login-common/ssl-proxy-openssl.c
@@ -80,7 +80,6 @@ static void plain_read(struct ssl_proxy 
 static void ssl_read(struct ssl_proxy *proxy);
 static void ssl_write(struct ssl_proxy *proxy);
 static void ssl_step(struct ssl_proxy *proxy);
-static void ssl_proxy_destroy(struct ssl_proxy *proxy);
 static void ssl_proxy_unref(struct ssl_proxy *proxy);
 
 static void ssl_params_corrupted(const char *path)
@@ -676,7 +675,7 @@ static void ssl_proxy_unref(struct ssl_p
 	main_unref();
 }
 
-static void ssl_proxy_destroy(struct ssl_proxy *proxy)
+void ssl_proxy_destroy(struct ssl_proxy *proxy)
 {
 	if (proxy->destroyed)
 		return;
