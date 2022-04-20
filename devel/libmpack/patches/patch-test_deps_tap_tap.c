$NetBSD: patch-test_deps_tap_tap.c,v 1.1 2022/04/20 17:56:29 nia Exp $

Fix redefinition of MAP_ANONYMOUS
https://github.com/libmpack/libmpack/issues/42

--- test/deps/tap/tap.c.orig    2017-03-19 21:48:19.000000000 +0100
+++ test/deps/tap/tap.c 2020-06-16 19:33:41.583771997 +0200
@@ -298,8 +298,12 @@
 #include <sys/param.h>
 #include <regex.h>
 
-#if defined __APPLE__ || defined BSD
+#ifndef MAP_ANONYMOUS
+#ifdef MAP_ANON
 #define MAP_ANONYMOUS MAP_ANON
+#else
+#error "System does not support mapping anonymous pages"
+#endif
 #endif
 
 /* Create a shared memory int to keep track of whether a piece of code executed
