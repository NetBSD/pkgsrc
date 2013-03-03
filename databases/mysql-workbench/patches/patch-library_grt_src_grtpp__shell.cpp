$NetBSD: patch-library_grt_src_grtpp__shell.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- library/grt/src/grtpp_shell.cpp.orig	2013-02-28 22:29:52.000000000 +0000
+++ library/grt/src/grtpp_shell.cpp
@@ -284,7 +284,7 @@ ShellCommand Shell::execute(const std::s
   // Automatically convert show to show(grt2Lua(pwd()))
   else if (strcmp(cmd, "show") == 0)
   {
-    preprocessed_cmd= g_strdup_printf("print("MYX_SHELL_CURNODE")\n");
+    preprocessed_cmd= g_strdup_printf("print(" MYX_SHELL_CURNODE ")\n");
     res= ShellCommandStatement;
   }
   // Automatically convert show objectname to show(getGlobal("objectname"))
