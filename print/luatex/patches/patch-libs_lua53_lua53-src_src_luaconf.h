$NetBSD: patch-libs_lua53_lua53-src_src_luaconf.h,v 1.1 2019/05/09 09:47:36 adam Exp $

Prepare @PREFIX@ for substituting the correct one in from the pkgsrc Makefile.
Solaris portability fix.

--- libs/lua53/lua53-src/src/luaconf.h.orig	2018-09-05 21:30:41.000000000 +0000
+++ libs/lua53/lua53-src/src/luaconf.h
@@ -200,7 +200,7 @@
 
 #else			/* }{ */
 
-#define LUA_ROOT	"/usr/local/"
+#define LUA_ROOT	"@PREFIX@"
 #define LUA_LDIR	LUA_ROOT "share/lua/" LUA_VDIR "/"
 #define LUA_CDIR	LUA_ROOT "lib/lua/" LUA_VDIR "/"
 #define LUA_PATH_DEFAULT  \
@@ -276,7 +276,7 @@
 ** default definition.
 */
 #if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) && \
-    defined(__ELF__)		/* { */
+    defined(__ELF__) && !defined(__sun)		/* { */
 #define LUAI_FUNC	__attribute__((visibility("hidden"))) extern
 #else				/* }{ */
 #define LUAI_FUNC	extern
