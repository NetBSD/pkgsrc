$NetBSD: patch-src_sat_sat__solver.cpp,v 1.1 2022/05/13 10:41:38 jperkin Exp $

Avoid ambiguous function call.

--- src/sat/sat_solver.cpp.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/sat/sat_solver.cpp
@@ -31,6 +31,8 @@ Revision History:
 // define to update glue during propagation
 #define UPDATE_GLUE
 
+using std::pow;
+
 namespace sat {
 
     solver::solver(params_ref const & p, reslimit& l):
