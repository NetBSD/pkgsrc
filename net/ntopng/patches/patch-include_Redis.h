$NetBSD: patch-include_Redis.h,v 1.1 2018/10/18 16:25:40 adam Exp $

Allow Redis connection through a socket.

--- include/Redis.h.orig	2018-10-18 14:09:01.000000000 +0000
+++ include/Redis.h
@@ -31,9 +31,7 @@ class Redis {
   redisContext *redis;
   Mutex *l;
   char *redis_host, *redis_password, *redis_version;
-#ifdef __linux__
   bool is_socket_connection;
-#endif
   u_int32_t num_requests, num_reconnections, num_redis_version;
   u_int16_t redis_port;
   u_int8_t redis_db_id;
