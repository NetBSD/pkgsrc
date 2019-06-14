$NetBSD: patch-CMakeModules_config.h.cmake,v 1.4 2019/06/14 15:59:32 bouyer Exp $

Fix compile problem due to ciso646.

--- CMakeModules/config.h.cmake.orig	2018-07-13 19:53:52.000000000 +0000
+++ CMakeModules/config.h.cmake
@@ -36,7 +36,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #if !defined( HAVE_STRCASECMP )
