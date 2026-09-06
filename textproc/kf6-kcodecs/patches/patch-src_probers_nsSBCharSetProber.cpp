$NetBSD: patch-src_probers_nsSBCharSetProber.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsSBCharSetProber.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsSBCharSetProber.cpp
@@ -6,7 +6,7 @@
 
 #include "nsSBCharSetProber.h"
 
-#include <format>
+#include <iomanip>
 
 namespace kencodingprober
 {
@@ -82,16 +82,16 @@ const char *nsSingleByteCharSetProber<Re
 template<bool Reversed>
 std::string nsSingleByteCharSetProber<Reversed>::StatusOutput(uint8_t /* indent */)
 {
-    return std::format( //
-        "{:1.3f} [{}] [{} {} {} {} | {}] [{} / {}]",
-        GetConfidence(),
-        GetCharSetName(),
-        mSeqCounters[0],
-        mSeqCounters[1],
-        mSeqCounters[2],
-        mSeqCounters[3],
-        mTotalSeqs,
-        mFreqChar,
-        mTotalChar);
+    std::stringstream ss;
+    ss << std::fixed << std::setprecision(3) << GetConfidence() 
+       << " [" << GetCharSetName() << "] ["
+       << mSeqCounters[0] << " "
+       << mSeqCounters[1] << " "
+       << mSeqCounters[2] << " "
+       << mSeqCounters[3] << " | "
+       << mTotalSeqs << "] ["
+       << mFreqChar << " / "
+       << mTotalChar << "]";
+    return ss.str();
 }
 }
