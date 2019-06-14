$NetBSD: patch-gcc_config_darwin-driver.c,v 1.1 2019/06/14 09:42:36 adam Exp $

Fix building on Darwin.

--- gcc/config/darwin-driver.c.orig	2019-05-21 21:45:22.000000000 +0000
+++ gcc/config/darwin-driver.c
@@ -27,6 +27,9 @@ along with GCC; see the file COPYING3.  
 #include "diagnostic-core.h"
 
 #ifndef CROSS_DIRECTORY_STRUCTURE
+#ifndef _Atomic
+#define _Atomic volatile
+#endif
 #include <sys/sysctl.h>
 #include "xregex.h"
 
