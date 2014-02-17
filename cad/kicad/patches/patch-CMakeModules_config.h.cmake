$NetBSD: patch-CMakeModules_config.h.cmake,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $

Fix compile problem due to ciso646.

--- CMakeModules/config.h.cmake.orig	2011-11-27 11:43:14.000000000 +0000
+++ CMakeModules/config.h.cmake
@@ -32,7 +32,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #if defined( HAVE_STRCASECMP )
