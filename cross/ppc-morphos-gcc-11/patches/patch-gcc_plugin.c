$NetBSD: patch-gcc_plugin.c,v 1.1 2024/03/27 23:26:29 js Exp $

--- gcc/plugin.c.orig	2024-03-27 23:11:57.373343495 +0000
+++ gcc/plugin.c
@@ -42,6 +42,8 @@ along with GCC; see the file COPYING3.
 #define NOMINMAX
 #endif
 #include <windows.h>
+#else
+#include <dlfcn.h>
 #endif
 
 #define GCC_PLUGIN_STRINGIFY0(X) #X
