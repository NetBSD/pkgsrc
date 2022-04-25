$NetBSD: patch-src_analyzer_boomanalyzer.cpp,v 1.1 2022/04/25 15:19:48 tnn Exp $

avoid ambiguous math functions

--- src/analyzer/boomanalyzer.cpp.orig	2022-03-22 20:09:13.757653684 +0000
+++ src/analyzer/boomanalyzer.cpp
@@ -38,6 +38,7 @@
 #include "analyzerbase.h"
 
 using Analyzer::Scope;
+using std::log10;
 
 const int BoomAnalyzer::kColumnWidth = 4;
 const int BoomAnalyzer::kMaxBandCount = 256;
