$NetBSD: patch-core_src_solver_parallel__tactic.cpp,v 1.1 2022/05/09 09:08:27 jperkin Exp $

Avoid ambiguous function calls.

--- core/src/solver/parallel_tactic.cpp.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/src/solver/parallel_tactic.cpp
@@ -52,6 +52,8 @@ tactic * mk_parallel_tactic(solver* s, p
 #include <cmath>
 #include <condition_variable>
 
+using std::pow;
+
 class parallel_tactic : public tactic {
 
 
