$NetBSD: patch-losbflib.c,v 1.2 2013/10/11 20:25:34 wiz Exp $

Fix build with lua-5.2.

--- losbflib.c.orig	2007-01-14 18:57:19.000000000 +0000
+++ losbflib.c
@@ -170,7 +170,7 @@ lua_osbf_createdb (lua_State * L)
   luaL_checktype (L, 1, LUA_TTABLE);
 
   /* get the number of classes to create */
-  num_classes = luaL_getn (L, 1);
+  num_classes = (int) lua_rawlen (L, 1);
 
   /* get number of buckets */
   buckets = luaL_checknumber (L, 2);
@@ -214,7 +214,7 @@ lua_osbf_removedb (lua_State * L)
   luaL_checktype (L, 1, LUA_TTABLE);
 
   /* get the number of classes to remove */
-  num_classes = luaL_getn (L, 1);
+  num_classes = (int) lua_rawlen (L, 1);
   removed = 0;
   lua_pushnil (L);		/* first key */
   while (lua_next (L, 1) != 0)
@@ -743,7 +743,7 @@ dir_gc (lua_State * L)
 
 /**********************************************************/
 
-static const struct luaL_reg osbf[] = {
+static const struct luaL_Reg osbf[] = {
   {"create_db", lua_osbf_createdb},
   {"remove_db", lua_osbf_removedb},
   {"config", lua_osbf_config},
@@ -767,6 +767,8 @@ static const struct luaL_reg osbf[] = {
 int
 luaopen_osbf (lua_State * L)
 {
+  size_t n_funcs;
+
   /* Open dir function */
   luaL_newmetatable (L, "LuaBook.dir");
   /* set its __gc field */
@@ -774,7 +776,13 @@ luaopen_osbf (lua_State * L)
   lua_pushcfunction (L, dir_gc);
   lua_settable (L, -3);
 
-  luaL_register (L, "osbf", osbf);
+  n_funcs = sizeof(osbf)/sizeof(*osbf) - 1;
+  lua_createtable( L, 0, n_funcs );
+  luaL_setfuncs( L, osbf, 0 );
+
+  lua_pushvalue( L, -1 );
+  lua_setglobal( L, "osbf" );
+
   set_info (L);
   return 1;
 }
