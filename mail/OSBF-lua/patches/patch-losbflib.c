$NetBSD: patch-losbflib.c,v 1.1 2013/07/05 14:31:40 wiz Exp $

Fix build with lua-5.2.

--- losbflib.c.orig	2007-01-14 18:57:19.000000000 +0000
+++ losbflib.c
@@ -743,7 +743,7 @@ dir_gc (lua_State * L)
 
 /**********************************************************/
 
-static const struct luaL_reg osbf[] = {
+static const struct luaL_Reg osbf[] = {
   {"create_db", lua_osbf_createdb},
   {"remove_db", lua_osbf_removedb},
   {"config", lua_osbf_config},
