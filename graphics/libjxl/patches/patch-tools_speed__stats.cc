$NetBSD: patch-tools_speed__stats.cc,v 1.1 2026/11/25 12:36:08 nros Exp $

* Fix ambiguity of pow on SunOS

--- tools/speed_stats.cc.orig	2026-11-25 13:28:39.997510869 +0000
+++ tools/speed_stats.cc
@@ -43,13 +43,13 @@ bool SpeedStats::GetSummary(SpeedStats::
   }
 
   // Prefer geomean unless numerically unreliable (too many reps)
-  if (pow(elapsed_[0], elapsed_.size()) < 1E100) {
+  if (std::pow(elapsed_[0], elapsed_.size()) < 1E100) {
     double product = 1.0;
     for (size_t i = 1; i < elapsed_.size(); ++i) {
       product *= elapsed_[i];
     }
 
-    s->central_tendency = pow(product, 1.0 / (elapsed_.size() - 1));
+    s->central_tendency = std::pow(product, 1.0 / (elapsed_.size() - 1));
     s->variability = 0.0;
     s->type = "geomean: ";
     if (std::isnormal(s->central_tendency)) return true;
