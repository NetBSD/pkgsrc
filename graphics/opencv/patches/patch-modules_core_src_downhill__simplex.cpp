$NetBSD: patch-modules_core_src_downhill__simplex.cpp,v 1.1 2015/10/08 17:45:59 fhajny Exp $

Avoid DS conflict on SunOS.

--- modules/core/src/downhill_simplex.cpp.orig	2015-06-03 17:21:34.000000000 +0000
+++ modules/core/src/downhill_simplex.cpp
@@ -450,6 +450,9 @@ protected:
 };
 
 
+#if defined(__sun)
+#undef DS
+#endif
 // both minRange & minError are specified by termcrit.epsilon;
 // In addition, user may specify the number of iterations that the algorithm does.
 Ptr<DownhillSolver> DownhillSolver::create( const Ptr<MinProblemSolver::Function>& f,
