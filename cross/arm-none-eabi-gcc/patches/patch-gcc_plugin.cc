$NetBSD: patch-gcc_plugin.cc,v 1.1 2026/04/20 03:49:24 js Exp $

--- gcc/plugin.cc.orig	2025-06-15 13:13:22.246840287 +0000
+++ gcc/plugin.cc
@@ -31,6 +31,8 @@ along with GCC; see the file COPYING3.
 #include "intl.h"
 #include "plugin.h"
 
+#include <dlfcn.h>
+
 #ifdef ENABLE_PLUGIN
 #include "plugin-version.h"
 #endif
