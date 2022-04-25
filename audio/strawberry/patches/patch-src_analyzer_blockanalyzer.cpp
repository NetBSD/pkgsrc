$NetBSD: patch-src_analyzer_blockanalyzer.cpp,v 1.1 2022/04/25 15:19:48 tnn Exp $

avoid ambiguous math functions

--- src/analyzer/blockanalyzer.cpp.orig	2022-03-26 20:21:03.329168404 +0000
+++ src/analyzer/blockanalyzer.cpp
@@ -36,6 +36,8 @@
 #include "analyzerbase.h"
 #include "fht.h"
 
+using std::log10;
+
 const int BlockAnalyzer::kHeight = 2;
 const int BlockAnalyzer::kWidth = 4;
 const int BlockAnalyzer::kMinRows = 3;       // arbitrary
