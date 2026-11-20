$NetBSD: patch-src_Redis.cpp,v 1.5 2026/11/20 13:12:04 adam Exp $

Allow Redis connection through a socket.

--- src/Redis.cpp.orig	2026-09-22 07:53:34.000000000 +0000
+++ src/Redis.cpp
@@ -40,9 +40,7 @@ Redis::Redis(const char* _redis_host, co
   redis_tls_key = tls_key ? strdup(tls_key) : NULL;
   redis_tls_skip_verify = tls_skip_verify;
   redis_port = _redis_port, redis_db_id = _redis_db_id;
-#ifdef __linux__
   is_socket_connection = false;
-#endif
 
 #ifdef HAVE_HIREDIS_SSL
   ssl_ctx = NULL;
@@ -118,14 +116,12 @@ void Redis::reconnectRedis(bool giveup_o
       redisFree(redis);
     }
 
-#ifdef __linux__
     struct stat buf;
 
     if (!stat(redis_host, &buf) && S_ISSOCK(buf.st_mode))
       redis = redisConnectUnixWithTimeout(redis_host, timeout),
       is_socket_connection = true;
     else
-#endif
       redis = redisConnectWithTimeout(redis_host, redis_port, timeout);
 
     if (redis == NULL || redis->err) {
@@ -205,13 +201,11 @@ void Redis::reconnectRedis(bool giveup_o
     exit(1);
   }
 
-#ifdef __linux__
   if (!is_socket_connection)
     ntop->getTrace()->traceEvent(TRACE_INFO,
                                  "Successfully connected to redis %s:%u@%u",
                                  redis_host, redis_port, redis_db_id);
   else
-#endif
     ntop->getTrace()->traceEvent(TRACE_INFO,
                                  "Successfully connected to redis %s@%u",
                                  redis_host, redis_db_id);
