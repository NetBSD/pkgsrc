$NetBSD: patch-src_login-common_ssl-proxy-openssl.c,v 1.1.2.2 2015/05/15 12:40:49 bsiegert Exp $

* Fix CVE-2015-3420 from revision 86f535375750 of dovecot-2.2.

--- src/login-common/ssl-proxy-openssl.c.orig	2015-01-29 16:01:15.000000000 +0000
+++ src/login-common/ssl-proxy-openssl.c
@@ -80,6 +80,7 @@ struct ssl_proxy {
 	unsigned int cert_broken:1;
 	unsigned int client_proxy:1;
 	unsigned int flushing:1;
+	unsigned int failed:1;
 };
 
 struct ssl_parameters {
@@ -131,6 +132,12 @@ static void ssl_proxy_ctx_set_crypto_par
 static int ssl_proxy_ctx_get_pkey_ec_curve_name(const struct master_service_ssl_settings *set);
 #endif
 
+static void ssl_proxy_destroy_failed(struct ssl_proxy *proxy)
+{
+	proxy->failed = TRUE;
+	ssl_proxy_destroy(proxy);
+}
+
 static unsigned int ssl_server_context_hash(const struct ssl_server_context *ctx)
 {
 	unsigned int i, g, h = 0;
@@ -462,7 +469,7 @@ static void ssl_handle_error(struct ssl_
 
 	if (errstr != NULL) {
 		proxy->last_error = i_strdup(errstr);
-		ssl_proxy_destroy(proxy);
+		ssl_proxy_destroy_failed(proxy);
 	}
 	ssl_proxy_unref(proxy);
 }
@@ -492,7 +499,7 @@ static void ssl_handshake(struct ssl_pro
 
 	if (proxy->handshake_callback != NULL) {
 		if (proxy->handshake_callback(proxy->handshake_context) < 0)
-			ssl_proxy_destroy(proxy);
+			ssl_proxy_destroy_failed(proxy);
 	}
 }
 
@@ -822,7 +829,8 @@ void ssl_proxy_destroy(struct ssl_proxy 
 	if (proxy->destroyed || proxy->flushing)
 		return;
 	proxy->flushing = TRUE;
-	ssl_proxy_flush(proxy);
+	if (!proxy->failed && proxy->handshaked)
+		ssl_proxy_flush(proxy);
 	proxy->destroyed = TRUE;
 
 	ssl_proxy_count--;
