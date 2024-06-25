$NetBSD: patch-src_LuaEngineNtop.cpp,v 1.1 2024/06/25 06:53:09 adam Exp $

Fix error: invalid conversion from 'char**' to 'const char**'.

--- src/LuaEngineNtop.cpp.orig	2024-06-25 06:42:44.129382916 +0000
+++ src/LuaEngineNtop.cpp
@@ -6296,7 +6296,7 @@ static int ntop_rrd_tune(lua_State *vm) 
   filename = argv[1];
 
   reset_rrd_state();
-  status = rrd_tune(argc, (char **)argv);
+  status = rrd_tune(argc, argv);
 
   if (status != 0) {
     char *err = rrd_get_error();
