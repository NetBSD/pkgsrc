$NetBSD: patch-core_src_sat_sat__solver.cpp,v 1.1 2022/05/09 09:08:27 jperkin Exp $

Avoid ambiguous function calls.

--- core/src/sat/sat_solver.cpp.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/src/sat/sat_solver.cpp
@@ -40,6 +40,8 @@ Revision History:
 #define ENABLE_TERNARY true
 #define DYNAMIC_VARS true
 
+using std::pow;
+
 namespace sat {
 
 
