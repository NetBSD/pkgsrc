$NetBSD: patch-src_analyzer_boomanalyzer.cpp,v 1.2 2023/08/22 20:26:30 adam Exp $

avoid ambiguous math functions

--- src/analyzer/boomanalyzer.cpp.orig	2023-08-21 18:29:36.000000000 +0000
+++ src/analyzer/boomanalyzer.cpp
@@ -36,6 +36,8 @@
 #include "fht.h"
 #include "analyzerbase.h"
 
+using std::log10;
+
 const int BoomAnalyzer::kColumnWidth = 4;
 const int BoomAnalyzer::kMaxBandCount = 256;
 const int BoomAnalyzer::kMinBandCount = 32;
