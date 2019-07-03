$NetBSD: patch-intern_elbeem_intern_solver_main.cpp,v 1.1 2019/07/03 10:21:08 markd Exp $

From b61af886ca3fb760831c96b641968c78ea242614 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Robert-Andr=C3=A9=20Mauchin?= <zebob.m@gmail.com>
Date: Wed, 3 Apr 2019 01:36:52 +0200
Subject: [PATCH] Fix for GCC9 new OpenMP data sharing

GCC 9 started implementing the OpenMP 4.0 and later behavior. When not using
default clause or when using default(shared), this makes no difference, but
if using default(none), previously the choice was not specify the const
qualified variables on the construct at all, or specify in firstprivate
clause. In GCC 9 as well as for OpenMP 4.0 compliance, those variables need
to be specified on constructs in which they are used, either in shared or
in firstprivate clause. Specifying them in firstprivate clause is one way to
achieve compatibility with both older GCC versions and GCC 9,
another option is to drop the default(none) clause.

This patch thus drops the default(none) clause.

See https://gcc.gnu.org/gcc-9/porting_to.html#ompdatasharing

Signed-off-by: Robert-André Mauchin <zebob.m@gmail.com>

diff --git a/intern/elbeem/intern/solver_main.cpp b/intern/elbeem/intern/solver_main.cpp
index 9fdefc7cc2a..97b4c109e1f 100644
--- intern/elbeem/intern/solver_main.cpp
+++ intern/elbeem/intern/solver_main.cpp
@@ -381,7 +381,7 @@ LbmFsgrSolver::mainLoop(const int lev)
 	GRID_REGION_INIT();
 #if PARALLEL==1
 	const int gDebugLevel = ::gDebugLevel;
-#pragma omp parallel default(none) num_threads(mNumOMPThreads) \
+#pragma omp parallel num_threads(mNumOMPThreads) \
   reduction(+: \
 	  calcCurrentMass,calcCurrentVolume, \
 		calcCellsFilled,calcCellsEmptied, \
@@ -1126,7 +1126,7 @@ LbmFsgrSolver::preinitGrids()
 		GRID_REGION_INIT();
 #if PARALLEL==1
 	const int gDebugLevel = ::gDebugLevel;
-#pragma omp parallel default(none) num_threads(mNumOMPThreads) \
+#pragma omp parallel num_threads(mNumOMPThreads) \
   reduction(+: \
 	  calcCurrentMass,calcCurrentVolume, \
 		calcCellsFilled,calcCellsEmptied, \
@@ -1164,7 +1164,7 @@ LbmFsgrSolver::standingFluidPreinit()
 	GRID_REGION_INIT();
 #if PARALLEL==1
 	const int gDebugLevel = ::gDebugLevel;
-#pragma omp parallel default(none) num_threads(mNumOMPThreads) \
+#pragma omp parallel num_threads(mNumOMPThreads) \
   reduction(+: \
 	  calcCurrentMass,calcCurrentVolume, \
 		calcCellsFilled,calcCellsEmptied, \
-- 
2.20.1

