$NetBSD: patch-gcc_plugin.c,v 1.1 2024/03/27 14:38:33 js Exp $

--- gcc/plugin.cc.orig	2024-03-27 12:15:57.011052559 +0000
+++ gcc/plugin.cc
@@ -43,6 +43,8 @@ along with GCC; see the file COPYING3.
 #endif
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
+#else
+#include <dlfcn.h>
 #endif
 
 #define GCC_PLUGIN_STRINGIFY0(X) #X
