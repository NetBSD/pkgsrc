$NetBSD: patch-Source__Files_Lua_lua__templates.h,v 1.1 2012/07/03 18:45:14 joerg Exp $

--- Source_Files/Lua/lua_templates.h.orig	2012-07-03 09:27:35.000000000 +0000
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
