$NetBSD: patch-src_windowfunctions.cpp,v 1.1 2022/04/25 13:49:49 tnn Exp $

Explicitly use std::pow, avoids ambiguous reference on SunOS.

--- src/windowfunctions.cpp.orig	2021-07-17 22:04:12.000000000 +0000
+++ src/windowfunctions.cpp
@@ -21,6 +21,8 @@
 
 #include "windowfunctions.h"
 
+using std::pow;
+
 namespace KeyFinder {
 
   double WindowFunction::window(temporal_window_t windowType, int n, int N) const {
