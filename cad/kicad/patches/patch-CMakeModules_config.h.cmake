$NetBSD: patch-CMakeModules_config.h.cmake,v 1.2 2016/02/03 19:34:33 bouyer Exp $

Fix compile problem due to ciso646.

--- ./CMakeModules/config.h.cmake.orig	2015-11-29 20:57:27.000000000 +0100
+++ ./CMakeModules/config.h.cmake	2015-12-11 17:46:32.000000000 +0100
@@ -36,7 +36,7 @@
 #cmakedefine HAVE_ISO646_H
 
 #if defined( HAVE_ISO646_H )
-#include <iso646.h>
+#include <ciso646>
 #endif
 
 #if defined( HAVE_STRCASECMP )
