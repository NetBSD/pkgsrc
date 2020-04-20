$NetBSD: patch-dcraw__api.cc,v 1.1 2020/04/20 00:38:36 joerg Exp $

--- dcraw_api.cc.orig	2020-04-19 19:59:33.951610818 +0000
+++ dcraw_api.cc
@@ -687,7 +687,7 @@ extern "C" {
         if (dark) {
 #ifdef _OPENMP
             #pragma omp parallel for schedule(static) default(none) \
-            shared(h,dark,rgbWB)
+            shared(h,dark,rgbWB,pixels,black)
 #endif
             for (int i = 0; i < pixels; i++) {
                 int cc;
@@ -700,7 +700,7 @@ extern "C" {
         } else {
 #ifdef _OPENMP
             #pragma omp parallel for schedule(static) default(none) \
-            shared(h,dark,rgbWB)
+            shared(h,dark,rgbWB,pixels,black)
 #endif
             for (int i = 0; i < pixels; i++) {
                 int cc;
