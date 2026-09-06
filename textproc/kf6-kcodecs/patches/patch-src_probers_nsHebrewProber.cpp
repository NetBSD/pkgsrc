$NetBSD: patch-src_probers_nsHebrewProber.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsHebrewProber.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsHebrewProber.cpp
@@ -7,7 +7,7 @@
 #include "nsHebrewProber.h"
 #include "nsSBCharSetProber.h"
 
-#include <format>
+#include <iomanip>
 
 // windows-1255 / ISO-8859-8 code points of interest
 #define FINAL_KAF ('\xea')
@@ -183,7 +183,11 @@ nsProbingState nsHebrewProber::GetState(
 std::string nsHebrewProber::StatusOutput(uint8_t indent)
 {
     indent += 2;
-    auto output = std::format("{:1.3f} [HEB] {} -- {}", GetConfidence(), mFinalCharLogicalScore, mFinalCharVisualScore);
+    std::stringstream ss;
+    ss << std::fixed << std::setprecision(3) << GetConfidence() 
+       << " [HEB] " << mFinalCharLogicalScore 
+       << " -- " << mFinalCharVisualScore;
+    auto output = ss.str();
     output += '\n' + std::string(indent, ' ') + "  Log: ";
     output += mLogicalProb->StatusOutput(indent);
     output += '\n' + std::string(indent, ' ') + "  Vis: ";
