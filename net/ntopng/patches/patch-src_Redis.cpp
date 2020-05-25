$NetBSD: patch-src_Redis.cpp,v 1.3 2020/05/25 20:26:51 adam Exp $

Allow Redis connection through a socket.

--- src/Redis.cpp.orig	2020-03-27 16:51:24.000000000 +0000
+++ src/Redis.cpp
@@ -36,9 +36,7 @@ Redis::Redis(const char *_redis_host, co
   redis_host = _redis_host ? strdup(_redis_host) : NULL;
   redis_password = _redis_password ? strdup(_redis_password) : NULL;
   redis_port = _redis_port, redis_db_id = _redis_db_id;
-#ifdef __linux__
   is_socket_connection = false;
-#endif
 
   memset(&stats, 0, sizeof(stats));
 
@@ -85,13 +83,11 @@ void Redis::reconnectRedis(bool giveup_o
       redisFree(redis);
     }
 
-#ifdef __linux__
     struct stat buf;
 
     if(!stat(redis_host, &buf) && S_ISSOCK(buf.st_mode))
       redis = redisConnectUnixWithTimeout(redis_host, timeout), is_socket_connection = true;
     else
-#endif
       redis = redisConnectWithTimeout(redis_host, redis_port, timeout);
 
     if(redis == NULL || redis->err) {
@@ -152,13 +148,11 @@ void Redis::reconnectRedis(bool giveup_o
     exit(1);
   }
 
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
