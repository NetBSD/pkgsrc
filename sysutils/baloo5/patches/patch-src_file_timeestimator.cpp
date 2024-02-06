$NetBSD: patch-src_file_timeestimator.cpp,v 1.2 2024/02/06 10:46:30 markd Exp $

Avoid ambiguous function call.

--- src/file/timeestimator.cpp.orig	2024-01-06 08:49:42.000000000 +0000
+++ src/file/timeestimator.cpp
@@ -9,6 +9,8 @@
 
 #include "timeestimator.h"
 
+using std::sqrt;
+
 using namespace Baloo;
 
 TimeEstimator::TimeEstimator() = default;
