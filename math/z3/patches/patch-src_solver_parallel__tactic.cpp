$NetBSD: patch-src_solver_parallel__tactic.cpp,v 1.1 2022/05/13 10:41:38 jperkin Exp $

Avoid ambiguous function call.

--- src/solver/parallel_tactic.cpp.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/solver/parallel_tactic.cpp
@@ -42,6 +42,8 @@ Notes:
 #include "solver/parallel_tactic.h"
 #include "solver/parallel_params.hpp"
 
+using std::pow;
+
 class parallel_tactic : public tactic {
 
 
