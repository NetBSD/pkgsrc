$NetBSD: patch-src_Redis.cpp,v 1.1 2016/04/08 16:59:07 adam Exp $

Allow Redis connection through unix socket.

--- src/Redis.cpp.orig	2016-04-06 11:41:42.000000000 +0000
+++ src/Redis.cpp
@@ -75,7 +75,12 @@ void Redis::reconnectRedis() {
     redisFree(redis);
   }
 
-  redis = redisConnectWithTimeout(redis_host, redis_port, timeout);
+  if (redis_host[0] == '/') {
+    redis = redisConnectUnixWithTimeout(redis_host, timeout);
+  }
+  else {
+    redis = redisConnectWithTimeout(redis_host, redis_port, timeout);
+  }
 
   while(num_attemps > 0) {
     if(redis) reply = (redisReply*)redisCommand(redis, "PING"); else reply = NULL;
