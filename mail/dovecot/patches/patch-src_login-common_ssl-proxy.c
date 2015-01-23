$NetBSD: patch-src_login-common_ssl-proxy.c,v 1.1 2015/01/23 12:17:47 wiz Exp $

Fix for CVE-2014-3430.
Based on http://hg.dovecot.org/dovecot-1.2/raw-rev/8ba4253adc9b

--- src/login-common/ssl-proxy.c.orig	2010-01-24 23:14:17.000000000 +0000
+++ src/login-common/ssl-proxy.c
@@ -55,6 +55,8 @@ const char *ssl_proxy_get_security_strin
 	return "";
 }
 
+void ssl_proxy_destroy(struct ssl_proxy *proxy ATTR_UNUSED) {}
+
 void ssl_proxy_free(struct ssl_proxy *proxy ATTR_UNUSED) {}
 
 unsigned int ssl_proxy_get_count(void)
