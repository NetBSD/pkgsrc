$NetBSD: patch-src_sat_sat__solver.cpp,v 1.2 2023/05/11 06:43:43 adam Exp $

Avoid ambiguous function call.

--- src/sat/sat_solver.cpp.orig	2023-05-08 13:23:26.000000000 +0000
+++ src/sat/sat_solver.cpp
@@ -37,6 +37,7 @@ Revision History:
 # include <xmmintrin.h>
 #endif
 
+using std::pow;
 
 namespace sat {
 
