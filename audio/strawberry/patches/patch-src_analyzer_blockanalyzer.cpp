$NetBSD: patch-src_analyzer_blockanalyzer.cpp,v 1.2 2026/05/19 14:36:35 adam Exp $

Avoid ambiguous math functions.

--- src/analyzer/blockanalyzer.cpp.orig	2026-04-17 18:27:01.902890881 +0000
+++ src/analyzer/blockanalyzer.cpp
@@ -36,6 +36,8 @@
 #include "analyzerbase.h"
 #include "fht.h"
 
+using std::log10;
+
 namespace {
 constexpr int kHeight = 2;
 constexpr int kWidth = 4;
