$NetBSD: patch-font3d_geometry.cc,v 1.1 2011/11/25 21:57:36 joerg Exp $

--- font3d/geometry.cc.orig	2011-11-25 18:27:42.000000000 +0000
+++ font3d/geometry.cc
@@ -31,7 +31,7 @@
 #include <math.h>
 #include <stddef.h>
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "vector.h"
 #include "geometry.h"
