$NetBSD: patch-noatun_modules_winskin_vis_winSkinFFT__impl.cpp,v 1.1 2014/07/10 17:00:21 jperkin Exp $

Avoid ambiguous function call.

--- noatun/modules/winskin/vis/winSkinFFT_impl.cpp.orig	2007-10-08 09:48:52.000000000 +0000
+++ noatun/modules/winskin/vis/winSkinFFT_impl.cpp
@@ -97,7 +97,7 @@ void WinSkinFFT_impl::calculateBlock(uns
     tmp=re*re+im*im;  
     // Here I check a new idea. We remove all low values
     // and all values over xyz to xyz.
-    fftArray[pos]=(int)(::sqrt(::sqrt(tmp)));
+    fftArray[pos]=(int)(::sqrt(::sqrt((float)tmp)));
     
     if (fftArray[pos]<=15) {
       max+=fftArray[pos];
