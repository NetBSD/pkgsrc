$NetBSD: patch-src_libstat_backends_redis__backend.cxx,v 1.1 2024/02/09 12:34:08 jperkin Exp $

Avoid _L conflict.

--- src/libstat/backends/redis_backend.cxx.orig	2024-02-09 12:25:23.853750146 +0000
+++ src/libstat/backends/redis_backend.cxx
@@ -57,8 +57,8 @@ struct redis_stat_ctx {
 
 	ucl_object_t *cur_stat = nullptr;
 
-	explicit redis_stat_ctx(lua_State *_L)
-		: L(_L)
+	explicit redis_stat_ctx(lua_State *_luaL)
+		: L(_luaL)
 	{
 	}
 
