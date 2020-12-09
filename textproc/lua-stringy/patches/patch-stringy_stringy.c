$NetBSD: patch-stringy_stringy.c,v 1.1 2020/12/09 11:12:47 nia Exp $

Argument to ctype functions must be unsigned char.

--- stringy/stringy.c.orig	2020-09-16 18:28:14.000000000 +0000
+++ stringy/stringy.c
@@ -164,9 +164,9 @@ static int strip(lua_State *L) {
     front = luaL_checklstring(L, 1, &size);
     end   = &front[size - 1];
 
-    for ( ; size && isspace(*front) ; size-- , front++)
+    for ( ; size && isspace((unsigned char)*front) ; size-- , front++)
     ;
-    for ( ; size && isspace(*end) ; size-- , end--)
+    for ( ; size && isspace((unsigned char)*end) ; size-- , end--)
     ;
 
     lua_pushlstring(L, front, (size_t)(end - front) + 1);
