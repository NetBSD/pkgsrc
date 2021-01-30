$NetBSD: patch-src_cal3d_converter.cpp,v 1.1 2021/01/30 08:57:02 mef Exp $

strcasecmp is not defined


--- src/cal3d_converter.cpp.orig	2006-05-29 02:35:09.000000000 +0900
+++ src/cal3d_converter.cpp	2021-01-30 17:44:09.947198360 +0900
@@ -10,6 +10,7 @@
 //****************************************************************************//
 
 #include "cal3d/cal3d.h"
+#include <cstring>
 
 #define SKELETON 0
 #define MESH 1
