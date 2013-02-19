$NetBSD: patch-intern_smoke_intern_WAVELET__NOISE.h,v 1.1 2013/02/19 22:32:35 joerg Exp $

--- intern/smoke/intern/WAVELET_NOISE.h.orig	2013-02-19 18:32:09.000000000 +0000
+++ intern/smoke/intern/WAVELET_NOISE.h
@@ -43,6 +43,7 @@
 #ifndef WAVELET_NOISE_H
 #define WAVELET_NOISE_H
 
+#include <string.h>
 #include <MERSENNETWISTER.h>
 
 #ifdef WIN32
