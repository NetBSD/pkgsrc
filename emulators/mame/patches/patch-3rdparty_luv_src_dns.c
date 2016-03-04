$NetBSD: patch-3rdparty_luv_src_dns.c,v 1.1 2016/03/04 12:47:13 wiz Exp $

Only use existing defines.

--- 3rdparty/luv/src/dns.c.orig	2016-02-24 07:02:17.000000000 +0000
+++ 3rdparty/luv/src/dns.c
@@ -150,13 +150,17 @@ static int luv_getaddrinfo(lua_State* L)
     if (lua_toboolean(L, -1)) hints->ai_flags |=  AI_ADDRCONFIG;
     lua_pop(L, 1);
 
+#if defined(AI_V4MAPPED)
     lua_getfield(L, 3, "v4mapped");
     if (lua_toboolean(L, -1)) hints->ai_flags |=  AI_V4MAPPED;
     lua_pop(L, 1);
+#endif
 
+#if defined(AI_ALL)
     lua_getfield(L, 3, "all");
     if (lua_toboolean(L, -1)) hints->ai_flags |=  AI_ALL;
     lua_pop(L, 1);
+#endif
 
     lua_getfield(L, 3, "numerichost");
     if (lua_toboolean(L, -1)) hints->ai_flags |=  AI_NUMERICHOST;
