$NetBSD: patch-library_grt_src_grtpp__shell__python.cpp,v 1.1 2012/12/25 21:12:31 joerg Exp $

--- library/grt/src/grtpp_shell_python.cpp.orig	2012-12-25 14:24:41.000000000 +0000
+++ library/grt/src/grtpp_shell_python.cpp
@@ -22,6 +22,7 @@
 
 #ifdef ENABLE_PYTHON_MODULES
 #include "grtpp_shell_python.h"
+#include "grtpp_shell_python_help.h"
 #include "base/string_utilities.h"
 
 using namespace grt;
@@ -194,8 +195,6 @@ int PythonShell::set_global_var(const st
 
 void PythonShell::show_help(const std::string &keyword)
 {
-  extern void grt_shell_show_python_help(GRT *grt, const char *command);
-  
   grt_shell_show_python_help(_grt, keyword.c_str());
 }
 
