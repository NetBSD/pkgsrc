$NetBSD: patch-dcraw__api.cc,v 1.2 2020/06/01 00:14:21 gdt Exp $

Drop default(none), because the OPENMP specification is unstable;
some versions prohibit declaring constants as shared and some require it.

--- dcraw_api.cc.orig	2015-06-16 03:58:38.000000000 +0000
+++ dcraw_api.cc
@@ -686,7 +686,7 @@ extern "C" {
             rgbWB[3] = rgbWB[1];
         if (dark) {
 #ifdef _OPENMP
-            #pragma omp parallel for schedule(static) default(none) \
+            #pragma omp parallel for schedule(static) \
             shared(h,dark,rgbWB)
 #endif
             for (int i = 0; i < pixels; i++) {
@@ -699,7 +699,7 @@ extern "C" {
             }
         } else {
 #ifdef _OPENMP
-            #pragma omp parallel for schedule(static) default(none) \
+            #pragma omp parallel for schedule(static) \
             shared(h,dark,rgbWB)
 #endif
             for (int i = 0; i < pixels; i++) {
