$NetBSD: patch-src_probers_nsUniversalDetector.cpp,v 1.1 2026/09/06 10:05:18 markd Exp $

<format> is a c++20 feature but not in gcc12, so do it the old way.

--- src/probers/nsUniversalDetector.cpp.orig	2026-08-07 20:39:15.000000000 +0000
+++ src/probers/nsUniversalDetector.cpp
@@ -12,8 +12,6 @@
 #include "nsMBCSGroupProber.h"
 #include "nsSBCSGroupProber.h"
 
-#include <format>
-
 namespace kencodingprober
 {
 //---------------------------------------------------------------------
