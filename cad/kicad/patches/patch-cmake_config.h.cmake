$NetBSD: patch-cmake_config.h.cmake,v 1.1 2023/02/13 07:59:01 tnn Exp $

From:
@NetBSD: patch-CMakeModules_config.h.cmake,v 1.4 2019/06/14 15:59:32 bouyer Exp @
Fix compile problem due to ciso646.

--- cmake/config.h.cmake.orig	2023-02-11 16:03:39.000000000 +0000
+++ cmake/config.h.cmake
@@ -38,7 +38,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #if !defined( HAVE_STRCASECMP )
