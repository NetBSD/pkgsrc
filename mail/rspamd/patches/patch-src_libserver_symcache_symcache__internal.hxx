$NetBSD: patch-src_libserver_symcache_symcache__internal.hxx,v 1.1 2022/10/30 15:38:54 jperkin Exp $

Avoid _L define.

--- src/libserver/symcache/symcache_internal.hxx.orig	2022-10-01 14:19:21.000000000 +0000
+++ src/libserver/symcache/symcache_internal.hxx
@@ -139,8 +139,8 @@ struct delayed_cache_condition {
 	int cbref;
 	lua_State *L;
 public:
-	delayed_cache_condition(std::string_view _sym, int _cbref, lua_State *_L) :
-		sym(_sym), cbref(_cbref), L(_L) {}
+	delayed_cache_condition(std::string_view _sym, int _cbref, lua_State *lstate) :
+		sym(_sym), cbref(_cbref), L(lstate) {}
 };
 
 class delayed_symbol_elt {
