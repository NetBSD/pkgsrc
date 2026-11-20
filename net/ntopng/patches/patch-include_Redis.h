$NetBSD: patch-include_Redis.h,v 1.4 2026/11/20 13:12:04 adam Exp $

Allow Redis connection through a socket.

--- include/Redis.h.orig	2026-09-22 07:53:34.000000000 +0000
+++ include/Redis.h
@@ -40,9 +40,7 @@ class Redis {
 #ifdef HAVE_HIREDIS_SSL
   redisSSLContext* ssl_ctx;
 #endif
-#ifdef __linux__
   bool is_socket_connection;
-#endif
   struct {
     u_int32_t num_expire, num_get, num_ttl, num_del, num_hget, num_hset,
         num_hdel, num_set, num_keys, num_hkeys, num_llen, num_other,
