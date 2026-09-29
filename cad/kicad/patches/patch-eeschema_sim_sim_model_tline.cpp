$NetBSD: patch-eeschema_sim_sim_model_tline.cpp,v 1.2 2026/09/29 16:11:56 bouyer Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/sim_model_tline.cpp.orig	2026-04-15 15:36:56.000000000 +0000
+++ eeschema/sim/sim_model_tline.cpp
@@ -26,6 +26,8 @@
 
 #include <fmt/core.h>
 
+using std::isnan;
+
 using SIMPARAM = SIM_MODEL::PARAM;
 
 
