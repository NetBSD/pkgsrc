$NetBSD: patch-src_probers_nsSBCSGroupProber.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsSBCSGroupProber.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsSBCSGroupProber.cpp
@@ -10,8 +10,8 @@
 #include "nsSBCharSetProber.h"
 #include "nsUtfProber.h"
 
-#include <format>
+#include <iomanip>
 
 namespace kencodingprober
 {
 nsSBCSGroupProber::nsSBCSGroupProber()
@@ -158,7 +156,9 @@ std::string nsSBCSGroupProber::StatusOut
     for (int i = 0; i < NUM_OF_SBCS_PROBERS; i++) {
         char state = !mIsActive[i] ? '-' : (i == mBestGuess) ? '*' : ' ';
         output += '\n' + std::string(indent, ' ');
-        output += std::format("{} #{:02}  SBCS: ", state, i);
+        std::stringstream ss;
+        ss << state << " #" << std::setw(2) << std::setfill('0') << i << "   SBCS: ";
+        output += ss.str();
         output += mProbers[i]->StatusOutput(indent);
     }
     return output;
