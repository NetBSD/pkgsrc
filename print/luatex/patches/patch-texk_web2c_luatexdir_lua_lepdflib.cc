$NetBSD: patch-texk_web2c_luatexdir_lua_lepdflib.cc,v 1.5 2018/05/13 12:46:27 markd Exp $

Build with poppler 0.64

--- texk/web2c/luatexdir/lua/lepdflib.cc.orig	2018-02-14 14:44:38.000000000 +0000
+++ texk/web2c/luatexdir/lua/lepdflib.cc
@@ -669,7 +669,7 @@ static int m_##in##_##function(lua_State
 #define m_poppler_get_GOOSTRING(in, function)                  \
 static int m_##in##_##function(lua_State * L)                  \
 {                                                              \
-    GooString *gs;                                             \
+    const GooString *gs;                                             \
     udstruct *uin;                                             \
     uin = (udstruct *) luaL_checkudata(L, 1, M_##in);          \
     if (uin->pd != NULL && uin->pd->pc != uin->pc)             \
@@ -1807,7 +1807,7 @@ static int m_Object_getNum(lua_State * L
 
 static int m_Object_getString(lua_State * L)
 {
-    GooString *gs;
+    const GooString *gs;
     udstruct *uin;
     uin = (udstruct *) luaL_checkudata(L, 1, M_Object);
     if (uin->pd != NULL && uin->pd->pc != uin->pc)
