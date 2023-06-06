$NetBSD: patch-eeschema_sim_sim_model_tline.cpp,v 1.1 2023/06/06 10:20:58 bouyer Exp $

Needs isnan in scope on NetBSD.

--- eeschema/sim/sim_model_tline.cpp.orig	2023-06-03 11:47:42.920032391 +0200
+++ eeschema/sim/sim_model_tline.cpp	2023-06-03 11:48:46.124305265 +0200
@@ -26,6 +26,8 @@
 
 #include <fmt/core.h>
 
+using std::isnan;
+
 using PARAM = SIM_MODEL::PARAM;
 
 
