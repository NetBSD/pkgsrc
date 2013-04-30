$NetBSD: patch-src_lua.cc,v 1.1 2013/04/30 22:20:22 joerg Exp $

--- src/lua.cc.orig	2013-04-30 19:57:33.000000000 +0000
+++ src/lua.cc
@@ -171,7 +171,7 @@ to_object(lua_State *L, int idx)
     if (lua_isnil(L,idx))
         return 0;
 
-    if (!is_object(L,idx)) {
+    if (!::is_object(L,idx)) {
         throwLuaError(L, "Cannot convert type to an Object");
         return 0;
     }
@@ -294,7 +294,7 @@ en_set_floor(lua_State *L)
 
     if (lua_isnil(L, 3))
         fl = 0;
-    else if (is_object(L,3)) {
+    else if (::is_object(L,3)) {
         fl = static_cast<Floor*>(*(static_cast<void**> (lua_touserdata(L,3))));
     	if( ! fl)
 	    throwLuaError(L, "object is no valid floor");
