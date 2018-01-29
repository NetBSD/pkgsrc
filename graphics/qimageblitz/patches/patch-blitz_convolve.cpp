$NetBSD: patch-blitz_convolve.cpp,v 1.1 2018/01/29 17:35:31 jperkin Exp $

Fix float* return type.

--- blitz/convolve.cpp.orig	2010-07-28 18:06:14.000000000 +0000
+++ blitz/convolve.cpp
@@ -940,7 +940,7 @@ float* BlitzPrivate::getBlurKernel(int &
     long i;
 
     if(sigma == 0.0)
-        return(false);
+        return(NULL);
     if(kernel_width == 0)
         kernel_width = 3;
 
