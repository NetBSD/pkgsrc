$NetBSD: patch-font3d_build.h,v 1.2 2020/05/14 19:27:41 joerg Exp $

--- font3d/build.h.orig	2000-07-16 02:37:31.000000000 +0000
+++ font3d/build.h
@@ -31,7 +31,7 @@
 #ifndef __BUILD_H__
 #define __BUILD_H__
 
-#include <iostream.h>
+#include <iostream>
 
 #include "truetype.h"
 #include "geometry.h"
