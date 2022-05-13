$NetBSD: patch-src_sat_ba__solver.cpp,v 1.1 2022/05/13 10:41:38 jperkin Exp $

Avoid ambiguous function call.

--- src/sat/ba_solver.cpp.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/sat/ba_solver.cpp
@@ -23,6 +23,7 @@ Revision History:
 #include "util/mpz.h"
 #include "sat/sat_simplifier_params.hpp"
 
+using std::pow;
 
 namespace sat {
 
