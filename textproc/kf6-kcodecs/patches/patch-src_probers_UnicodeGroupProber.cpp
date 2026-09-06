$NetBSD: patch-src_probers_UnicodeGroupProber.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/UnicodeGroupProber.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/UnicodeGroupProber.cpp
@@ -7,8 +7,8 @@
 #include "UnicodeGroupProber.h"
 #include "nsUtfProber.h"
 
-#include <format>
+#include <iomanip>
 
 namespace kencodingprober
 {
 UnicodeGroupProber::UnicodeGroupProber()
@@ -98,7 +96,9 @@ std::string UnicodeGroupProber::StatusOu
     for (int i = 0; i < NUM_OF_UTF_PROBERS; i++) {
         char state = !mIsActive[i] ? '-' : (i == mBestGuess) ? '*' : ' ';
         output += '\n' + std::string(indent, ' ');
-        output += std::format("{} #{:02}   UTF: ", state, i);
+        std::stringstream ss;
+        ss << state << " #" << std::setw(2) << std::setfill('0') << i << "   UTF: ";
+        output += ss.str();
         output += mProbers[i]->StatusOutput(indent);
     }
     return output;
