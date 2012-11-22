$NetBSD: patch-tools_clang_lib_Driver_Tools.cpp,v 1.1 2012/11/22 22:45:15 marino Exp $

DragonFly no longer has gcc 4.1 in base, so clang stopped working.
We prefer to use gcc 4.7 if available due to a better libstdc++.
The fallback is gcc 4.4 which has been available for several years.

--- tools/clang/lib/Driver/Tools.cpp.orig	2012-04-18 21:32:25.000000000 +0000
+++ tools/clang/lib/Driver/Tools.cpp
@@ -5499,14 +5499,21 @@ void dragonfly::Link::ConstructJob(Compi
       !Args.hasArg(options::OPT_nodefaultlibs)) {
     // FIXME: GCC passes on -lgcc, -lgcc_pic and a whole lot of
     //         rpaths
-    CmdArgs.push_back("-L/usr/lib/gcc41");
+    CmdArgs.push_back("-L/usr/lib/gcc47");
+    CmdArgs.push_back("-L/usr/lib/gcc44");
 
     if (!Args.hasArg(options::OPT_static)) {
       CmdArgs.push_back("-rpath");
-      CmdArgs.push_back("/usr/lib/gcc41");
+      CmdArgs.push_back("/usr/lib/gcc47");
 
       CmdArgs.push_back("-rpath-link");
-      CmdArgs.push_back("/usr/lib/gcc41");
+      CmdArgs.push_back("/usr/lib/gcc47");
+
+      CmdArgs.push_back("-rpath");
+      CmdArgs.push_back("/usr/lib/gcc44");
+
+      CmdArgs.push_back("-rpath-link");
+      CmdArgs.push_back("/usr/lib/gcc44");
 
       CmdArgs.push_back("-rpath");
       CmdArgs.push_back("/usr/lib");
