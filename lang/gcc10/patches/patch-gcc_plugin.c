$NetBSD: patch-gcc_plugin.c,v 1.2 2024/04/01 14:33:57 js Exp $

Support dynamic link interface functions.

Needs to come after the other includes as those add some defines that change
behavior (breaks QNX otherwise).

--- gcc/plugin.c.orig	2023-07-07 07:08:19.000000000 +0000
+++ gcc/plugin.c
@@ -30,6 +30,8 @@ along with GCC; see the file COPYING3.  
 #include "intl.h"
 #include "plugin.h"
 
+#include <dlfcn.h>
+
 #ifdef ENABLE_PLUGIN
 #include "plugin-version.h"
 #endif
