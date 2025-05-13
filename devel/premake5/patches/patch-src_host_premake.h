$NetBSD: patch-src_host_premake.h,v 1.1 2025/05/13 14:21:57 triaxx Exp $

Fix header paths to be consistent with include directories provided by pkgsrc.

--- src/host/premake.h.orig	2025-05-13 13:51:10.681237075 +0000
+++ src/host/premake.h
@@ -10,9 +10,9 @@
 #include "lauxlib.h"
 #include "lualib.h"
 #else
-#include <lua5.3/lua.h>
-#include <lua5.3/lauxlib.h>
-#include <lua5.3/lualib.h>
+#include <lua.h>
+#include <lauxlib.h>
+#include <lualib.h>
 #endif
 
 #include <stdint.h>
