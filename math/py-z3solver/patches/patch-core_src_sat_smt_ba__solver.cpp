$NetBSD: patch-core_src_sat_smt_ba__solver.cpp,v 1.1 2022/05/09 09:08:27 jperkin Exp $

Avoid ambiguous function calls.

--- core/src/sat/smt/ba_solver.cpp.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/src/sat/smt/ba_solver.cpp
@@ -23,6 +23,7 @@ Author:
 #include "sat/sat_simplifier_params.hpp"
 #include "sat/sat_xor_finder.h"
 
+using std::pow;
 
 namespace sat {
 
