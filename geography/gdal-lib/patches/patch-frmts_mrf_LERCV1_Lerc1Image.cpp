$NetBSD: patch-frmts_mrf_LERCV1_Lerc1Image.cpp,v 1.1 2023/08/27 11:00:00 tnn Exp $

https://github.com/OSGeo/gdal/commit/732f80bdb6da2084e2a83e7eab032dc899307ad7

--- frmts/mrf/LERCV1/Lerc1Image.cpp.orig	2022-10-21 14:57:17.000000000 +0000
+++ frmts/mrf/LERCV1/Lerc1Image.cpp
@@ -22,6 +22,7 @@ Contributors:  Thomas Maurer
 */
 
 #include "Lerc1Image.h"
+#include <cstdint>
 #include <cmath>
 #include <cfloat>
 #include <string>
