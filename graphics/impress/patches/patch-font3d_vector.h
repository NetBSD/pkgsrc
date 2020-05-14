$NetBSD: patch-font3d_vector.h,v 1.2 2020/05/14 19:27:41 joerg Exp $

--- font3d/vector.h.orig	2000-07-16 02:37:31.000000000 +0000
+++ font3d/vector.h
@@ -73,7 +73,9 @@
 #define __VECTOR_H__
 
 #include <math.h>
-#include <iostream.h>
+#include <iostream>
+
+using std::ostream;
 
    class vector
    {
