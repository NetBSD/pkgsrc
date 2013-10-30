$NetBSD: patch-scrext.c,v 1.2 2013/10/30 10:43:24 obache Exp $

* Lua-5.2 API change (lua_objlen was renamed lua_rawlen).

--- scrext.c.orig	2010-08-05 06:24:33.000000000 +0000
+++ scrext.c
@@ -153,6 +153,13 @@ bool scrextkill(void *scr){
 #include "lualib.h"
 #include "lauxlib.h"
 
+#ifdef LUA_VERSION_NUM
+# if (LUA_VERSION_NUM >= 502)
+#undef lua_objlen
+#define lua_objlen lua_rawlen
+# endif
+#endif
+
 #define SERVVAR      "_serv_"            // global variable name for server resources
 #define ITERVAR      "_iter_"            // global variable name for iterator
 #define MRMAPVAR     "_mrmap_"           // global variable name for mapreduce mapper
