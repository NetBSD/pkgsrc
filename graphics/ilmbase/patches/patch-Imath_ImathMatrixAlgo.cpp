$NetBSD: patch-Imath_ImathMatrixAlgo.cpp,v 1.1 2013/12/26 15:59:27 tron Exp $

Fix build with SunStudio compiler under Solaris.

--- Imath/ImathMatrixAlgo.cpp.orig	2013-06-18 20:51:38.000000000 +0100
+++ Imath/ImathMatrixAlgo.cpp	2013-12-26 15:22:33.000000000 +0000
@@ -44,6 +44,7 @@
 
 #include "ImathMatrixAlgo.h"
 #include <cmath>
+#include <algorithm>
 
 #if defined(OPENEXR_DLL)
     #define EXPORT_CONST __declspec(dllexport)
