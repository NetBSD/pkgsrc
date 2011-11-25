$NetBSD: patch-src_cal3d_platform.cpp,v 1.1 2011/11/25 21:56:18 joerg Exp $

--- src/cal3d/platform.cpp.orig	2011-11-25 16:04:14.000000000 +0000
+++ src/cal3d/platform.cpp
@@ -16,6 +16,7 @@
 // Includes                                                                   //
 //****************************************************************************//
 
+#include <cstring>
 #include "cal3d/platform.h"
 
  /*****************************************************************************/
