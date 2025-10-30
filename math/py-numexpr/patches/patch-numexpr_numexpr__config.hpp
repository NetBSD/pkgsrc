$NetBSD: patch-numexpr_numexpr__config.hpp,v 1.2 2025/10/30 15:19:43 adam Exp $

Fix build on NetBSD.

--- numexpr/numexpr_config.hpp.orig	2025-10-13 15:50:29.000000000 +0000
+++ numexpr/numexpr_config.hpp
@@ -42,7 +42,7 @@
 #endif
 #include <cmath>
 //no single precision version of signbit in C++ standard
-inline bool signbitf(float x) { return signbit((double)x); }
+inline bool signbitf(float x) { return std::signbit((double)x); }
 
 #ifdef _WIN32
   #ifndef __MINGW32__
