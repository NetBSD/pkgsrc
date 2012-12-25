$NetBSD: patch-library_grt_src_grtpp__shell__lua.cpp,v 1.1 2012/12/25 21:12:31 joerg Exp $

--- library/grt/src/grtpp_shell_lua.cpp.orig	2012-12-25 14:27:07.000000000 +0000
+++ library/grt/src/grtpp_shell_lua.cpp
@@ -37,6 +37,7 @@
   #include <Windows.h>
 #endif
 
+extern void myx_grt_shell_show_help(grt::GRT *grt, const char *command);
 
 using namespace grt;
 using namespace base;
@@ -207,7 +208,6 @@ int LuaShell::set_global_var(const std::
 
 void LuaShell::show_help(const std::string &keyword)
 {
-  extern void myx_grt_shell_show_help(grt::GRT *grt, const char *command);
   
   myx_grt_shell_show_help(_grt, keyword.c_str());
 }
