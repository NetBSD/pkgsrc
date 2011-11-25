$NetBSD: patch-font3d_build.h,v 1.1 2011/11/25 21:57:36 joerg Exp $

--- font3d/build.h.orig	2011-11-25 18:27:44.000000000 +0000
+++ font3d/build.h
@@ -31,7 +31,9 @@
 #ifndef __BUILD_H__
 #define __BUILD_H__
 
-#include <iostream.h>
+#include <iostream>
+
+using namespace std;
 
 #include "truetype.h"
 #include "geometry.h"
