$NetBSD: patch-src_file_timeestimator.cpp,v 1.1 2022/05/17 17:17:57 jperkin Exp $

Avoid ambiguous function call.

--- src/file/timeestimator.cpp.orig	2022-04-02 10:13:54.000000000 +0000
+++ src/file/timeestimator.cpp
@@ -10,6 +10,8 @@
 #include "timeestimator.h"
 #include "filecontentindexerprovider.h"
 
+using std::sqrt;
+
 using namespace Baloo;
 
 TimeEstimator::TimeEstimator(QObject* parent)
