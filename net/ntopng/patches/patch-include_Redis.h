$NetBSD: patch-include_Redis.h,v 1.3 2023/11/20 17:59:35 adam Exp $

Allow Redis connection through a socket.

--- include/Redis.h.orig	2023-11-02 14:11:55.000000000 +0000
+++ include/Redis.h
@@ -31,9 +31,7 @@ class Redis {
   redisContext *redis;
   Mutex *l;
   char *redis_host, *redis_password, *redis_version;
-#ifdef __linux__
   bool is_socket_connection;
-#endif
   struct {
     u_int32_t num_expire, num_get, num_ttl, num_del, num_hget, num_hset,
         num_hdel, num_set, num_keys, num_hkeys, num_llen, num_other,
