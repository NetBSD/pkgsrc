$NetBSD: patch-LUAHandler.cpp,v 1.1 2013/09/15 20:07:07 tsutsui Exp $

- Try to adapt to lua 5.2 API changes.

--- LUAHandler.cpp.orig	2013-08-12 13:58:38.000000000 +0000
+++ LUAHandler.cpp
@@ -559,11 +559,11 @@ void LUAHandler::init(ONScripter *ons, S
     this->ons = ons;
     this->sh = sh;
     
-    state = lua_open();
+    state = luaL_newstate();
     luaL_openlibs(state);
 
-    lua_pushvalue(state, LUA_GLOBALSINDEX);
-    luaL_register(state, NULL, lua_lut);
+    lua_pushglobaltable(state);
+    luaL_setfuncs(state, lua_lut, 0);
     
     lua_pushlightuserdata(state, this);
     lua_setglobal(state, ONS_LUA_HANDLER_PTR);
