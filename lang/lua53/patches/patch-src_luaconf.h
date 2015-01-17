$NetBSD: patch-src_luaconf.h,v 1.1.1.1 2015/01/17 17:50:23 alnsn Exp $

--- src/luaconf.h.orig	2014-12-29 13:27:55.000000000 +0000
+++ src/luaconf.h
@@ -175,7 +175,9 @@
 
 #else			/* }{ */
 
+#ifndef LUA_ROOT
 #define LUA_ROOT	"/usr/local/"
+#endif
 #define LUA_LDIR	LUA_ROOT "share/lua/" LUA_VDIR "/"
 #define LUA_CDIR	LUA_ROOT "lib/lua/" LUA_VDIR "/"
 #define LUA_PATH_DEFAULT  \
@@ -251,7 +253,7 @@
 ** default definition.
 */
 #if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) && \
-    defined(__ELF__)		/* { */
+    defined(__ELF__) && !defined(__sun)		/* { */
 #define LUAI_FUNC	__attribute__((visibility("hidden"))) extern
 #else				/* }{ */
 #define LUAI_FUNC	extern
