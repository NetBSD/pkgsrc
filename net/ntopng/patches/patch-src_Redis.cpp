$NetBSD: patch-src_Redis.cpp,v 1.2 2018/10/18 16:25:40 adam Exp $

Allow Redis connection through a socket.

--- src/Redis.cpp.orig	2018-09-19 15:35:27.000000000 +0000
+++ src/Redis.cpp
@@ -35,9 +35,7 @@ Redis::Redis(const char *_redis_host, co
   redis_host = _redis_host ? strdup(_redis_host) : NULL;
   redis_password = _redis_password ? strdup(_redis_password) : NULL;
   redis_port = _redis_port, redis_db_id = _redis_db_id;
-#ifdef __linux__
   is_socket_connection = false;
-#endif
 
   num_requests = num_reconnections = 0;
   redis = NULL, operational = false;
@@ -75,13 +73,11 @@ void Redis::reconnectRedis() {
     ntop->getTrace()->traceEvent(TRACE_NORMAL, "Redis has disconnected: reconnecting...");
     redisFree(redis);
   }
-#ifdef __linux__
   struct stat buf;
 
   if(!stat(redis_host, &buf) && S_ISSOCK(buf.st_mode))
     redis = redisConnectUnixWithTimeout(redis_host, timeout), is_socket_connection = true;
   else
-#endif
     redis = redisConnectWithTimeout(redis_host, redis_port, timeout);
 
   if(redis_password) {
@@ -122,13 +118,11 @@ void Redis::reconnectRedis() {
       goto redis_error_handler;
     } else {
       freeReplyObject(reply);
-#ifdef __linux__
       if(!is_socket_connection)
 	ntop->getTrace()->traceEvent(TRACE_NORMAL,
 				     "Successfully connected to redis %s:%u@%u",
 				     redis_host, redis_port, redis_db_id);
       else
-#endif
 	ntop->getTrace()->traceEvent(TRACE_NORMAL,
 				     "Successfully connected to redis %s@%u",
 				     redis_host, redis_db_id);
