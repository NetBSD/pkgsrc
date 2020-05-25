$NetBSD: patch-include_Redis.h,v 1.2 2020/05/25 20:26:51 adam Exp $

Allow Redis connection through a socket.

--- include/Redis.h.orig	2020-03-27 16:51:24.000000000 +0000
+++ include/Redis.h
@@ -31,9 +31,7 @@ class Redis {
   redisContext *redis;
   Mutex *l;
   char *redis_host, *redis_password, *redis_version;
-#ifdef __linux__
   bool is_socket_connection;
-#endif
   struct {
     u_int32_t num_expire, num_get, num_ttl, num_del,
       num_hget, num_hset, num_hdel, num_set,
