$NetBSD: patch-Source__Files_Lua_lua__templates.h,v 1.3 2012/12/22 20:01:02 joerg Exp $

--- Source_Files/Lua/lua_templates.h.orig	2012-12-22 18:58:20.000000000 +0000
+++ Source_Files/Lua/lua_templates.h
@@ -496,7 +496,7 @@ public:
 	static index_t ToIndex(lua_State *L, int index) {
 		index_t to;
 		if(lua_isnil(L, index)) return -1;
-		else if(_lookup(L, index, to)) return to;
+		else if(L_Enum<name, index_t>::_lookup(L, index, to)) return to;
 		else {
 			std::string error;
 			if(lua_isnumber(L, index) || lua_isstring(L, index))
