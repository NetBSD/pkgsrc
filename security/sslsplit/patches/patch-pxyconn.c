$NetBSD: patch-pxyconn.c,v 1.1 2024/04/29 09:27:40 nia Exp $

Fix building with OpenSSL 3.

https://github.com/droe/sslsplit/commit/e17de8454a65d2b9ba432856971405dfcf1e7522.patch

--- pxyconn.c.orig	2019-08-30 11:09:00.000000000 +0000
+++ pxyconn.c
@@ -72,6 +72,10 @@ bufferevent_openssl_set_allow_dirty_shut
 }
 #endif /* LIBEVENT_VERSION_NUMBER < 0x02010000 */
 
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+#define ERR_GET_FUNC(x) 0
+#define ERR_func_error_string(x) ""
+#endif
 
 /*
  * Maximum size of data to buffer per connection direction before
