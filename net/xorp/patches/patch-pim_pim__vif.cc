$NetBSD: patch-pim_pim__vif.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- pim/pim_vif.cc.orig	2012-07-03 16:18:50.000000000 +0000
+++ pim/pim_vif.cc
@@ -1778,7 +1778,7 @@ PimVif::upstream_join_timer_t_suppressed
 // Compute the randomized 't_override' interval value for Upstream Join Timer:
 // t_override = rand(0, Effective_Override_Interval(I))
 //
-const struct TimeVal&
+const class TimeVal&
 PimVif::upstream_join_timer_t_override() const
 {
     static TimeVal tv;
