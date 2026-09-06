$NetBSD: patch-src_probers_nsLatin1Prober.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsLatin1Prober.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsLatin1Prober.cpp
@@ -6,7 +6,7 @@
 
 #include "nsLatin1Prober.h"
 
-#include <format>
+#include <iomanip>
 #include <numeric>
 
 #define UDF 0 // undefined
@@ -135,13 +135,13 @@ float nsLatin1Prober::GetConfidence(void
 
 std::string nsLatin1Prober::StatusOutput(uint8_t /* indent */)
 {
-    return std::format( //
-        "{:1.3f} [{}] [{} {} {} {}]",
-        GetConfidence(),
-        GetCharSetName(),
-        mFreqCounter[0],
-        mFreqCounter[1],
-        mFreqCounter[2],
-        mFreqCounter[3]);
+    std::stringstream ss;
+    ss << std::fixed << std::setprecision(3) << GetConfidence() 
+       << " [" << GetCharSetName() << "] ["
+       << mFreqCounter[0] << " "
+       << mFreqCounter[1] << " "
+       << mFreqCounter[2] << " "
+       << mFreqCounter[3] << "]";
+    return ss.str();
 }
 }
