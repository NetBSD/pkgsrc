$NetBSD: patch-src_probers_nsCharSetProber.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsCharSetProber.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsCharSetProber.cpp
@@ -8,7 +8,7 @@
 
 #include <kcodecs_prober_debug.h>
 
-#include <format>
+#include <iomanip>
 
 namespace kencodingprober
 {
@@ -112,6 +112,8 @@ void nsCharSetProber::DumpStatus()
 
 std::string nsCharSetProber::StatusOutput(uint8_t /* indent */)
 {
-    return std::format("{:1.3f} [{}]", GetConfidence(), GetCharSetName());
+    std::stringstream ss;
+    ss << std::fixed << std::setprecision(3) << GetConfidence() << " [" << GetCharSetName() << "]";
+    return ss.str();
 }
 }
