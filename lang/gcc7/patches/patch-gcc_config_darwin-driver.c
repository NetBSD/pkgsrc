$NetBSD: patch-gcc_config_darwin-driver.c,v 1.2 2020/03/03 12:58:42 adam Exp $

Fix building on Darwin.

--- gcc/config/darwin-driver.c.orig	2020-03-03 07:12:59.000000000 +0000
+++ gcc/config/darwin-driver.c
@@ -112,6 +112,9 @@ validate_macosx_version_min (const char 
 }
 
 #ifndef CROSS_DIRECTORY_STRUCTURE
+#ifndef _Atomic
+#define _Atomic volatile
+#endif
 #include <sys/sysctl.h>
 #include "xregex.h"
 
