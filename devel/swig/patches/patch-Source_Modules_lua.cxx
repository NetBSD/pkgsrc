$NetBSD: patch-Source_Modules_lua.cxx,v 1.1 2013/07/06 23:11:51 wiz Exp $

Fix for lua-5.2.

--- Source/Modules/lua.cxx.orig	2008-06-21 15:23:02.000000000 +0000
+++ Source/Modules/lua.cxx
@@ -264,7 +264,7 @@ public:
     Printf(f_header, "#define SWIG_init_user luaopen_%s_user\n\n", module);
     Printf(f_header, "#define SWIG_LUACODE   luaopen_%s_luacode\n\n", module);
 
-    Printf(s_cmd_tab, "\nstatic const struct luaL_reg swig_commands[] = {\n");
+    Printf(s_cmd_tab, "\nstatic const struct luaL_Reg swig_commands[] = {\n");
     Printf(s_var_tab, "\nstatic swig_lua_var_info swig_variables[] = {\n");
     Printf(s_const_tab, "\nstatic swig_lua_const_info swig_constants[] = {\n");
     Printf(f_wrappers, "#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
