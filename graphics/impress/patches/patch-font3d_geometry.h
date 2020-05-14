$NetBSD: patch-font3d_geometry.h,v 1.2 2020/05/14 19:27:41 joerg Exp $

--- font3d/geometry.h.orig	2000-07-16 02:37:31.000000000 +0000
+++ font3d/geometry.h
@@ -31,8 +31,7 @@
 #ifndef __GEOMETRY_H__
 #define __GEOMETRY_H__
 
-#include <iostream.h>
-
+#include <iostream>
 #include "vector.h"
 
 #define  TRUE          1
