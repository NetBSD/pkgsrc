$NetBSD: patch-src_probers_nsMBCSGroupProber.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsMBCSGroupProber.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsMBCSGroupProber.cpp
@@ -13,8 +13,8 @@
 #include "nsSJISProber.h"
 #include "nsUtfProber.h"
 
-#include <format>
+#include <iomanip>
 
 namespace kencodingprober
 {
 
@@ -188,7 +186,9 @@ std::string nsMBCSGroupProber::StatusOut
     for (int i = 0; i < NUM_OF_PROBERS; i++) {
         char state = !mIsSelected[i] ? '.' : !mIsActive[i] ? '-' : (i == mBestGuess) ? '*' : ' ';
         output += '\n' + std::string(indent, ' ');
-        output += std::format("{} #{:02}  MBCS: ", state, i);
+        std::stringstream ss;
+        ss << state << " #" << std::setw(2) << std::setfill('0') << i << "   MBCS: ";
+        output += ss.str();
         output += mProbers[i]->StatusOutput(indent);
     }
     return output;
