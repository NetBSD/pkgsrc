$NetBSD: patch-intern_cycles_kernel_light_tree.h,v 1.1 2024/07/25 06:00:38 ryoon Exp $

--- intern/cycles/kernel/light/tree.h.orig	2024-07-02 09:35:59.386137324 +0000
+++ intern/cycles/kernel/light/tree.h
@@ -190,7 +190,7 @@ ccl_device void light_tree_importance(co
     cos_min_outgoing_angle = 1.0f;
   }
   else if ((bcone.theta_o + bcone.theta_e > M_PI_F) ||
-           (cos_theta_minus_theta_u > cos(bcone.theta_o + bcone.theta_e)))
+           (double(cos_theta_minus_theta_u) > cos(bcone.theta_o + bcone.theta_e)))
   {
     /* theta' = theta - theta_o - theta_u < theta_e */
     kernel_assert(
@@ -220,7 +220,7 @@ ccl_device void light_tree_importance(co
   float cos_max_outgoing_angle;
   const float cos_theta_plus_theta_u = cos_theta * cos_theta_u - sin_theta * sin_theta_u;
   if (bcone.theta_e - bcone.theta_o < 0 || cos_theta < 0 || cos_theta_u < 0 ||
-      cos_theta_plus_theta_u < cos(bcone.theta_e - bcone.theta_o))
+      double(cos_theta_plus_theta_u) < cos(bcone.theta_e - bcone.theta_o))
   {
     min_importance = 0.0f;
   }
