$NetBSD: patch-src_login-common_ssl-proxy.h,v 1.1 2015/01/23 12:17:47 wiz Exp $

Fix for CVE-2014-3430.
Based on http://hg.dovecot.org/dovecot-1.2/raw-rev/8ba4253adc9b

--- src/login-common/ssl-proxy.h.orig	2009-06-27 04:49:34.000000000 +0000
+++ src/login-common/ssl-proxy.h
@@ -24,6 +24,7 @@ const char *ssl_proxy_get_peer_name(stru
 bool ssl_proxy_is_handshaked(const struct ssl_proxy *proxy) ATTR_PURE;
 const char *ssl_proxy_get_last_error(const struct ssl_proxy *proxy) ATTR_PURE;
 const char *ssl_proxy_get_security_string(struct ssl_proxy *proxy);
+void ssl_proxy_destroy(struct ssl_proxy *proxy);
 void ssl_proxy_free(struct ssl_proxy *proxy);
 
 /* Return number of active SSL proxies */
