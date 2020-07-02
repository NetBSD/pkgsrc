$NetBSD: patch-src_luv.c,v 1.1 2020/07/02 20:48:09 nia Exp $

Support Lua 5.4

--- src/luv.c.orig	2020-04-19 08:44:19.000000000 +0000
+++ src/luv.c
@@ -16,7 +16,7 @@
  */
 
 #include <lua.h>
-#if (LUA_VERSION_NUM != 503)
+#if (LUA_VERSION_NUM < 503)
 #include "compat-5.3.h"
 #endif
 #include "luv.h"
