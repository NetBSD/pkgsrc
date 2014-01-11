$NetBSD: patch-src_sp-item-rm-unsatisfied-cns.cpp,v 1.1 2014/01/11 17:48:52 wiz Exp $

Fix compilation with clang/libc++.

--- src/sp-item-rm-unsatisfied-cns.cpp.orig	2011-07-08 18:25:09.000000000 +0000
+++ src/sp-item-rm-unsatisfied-cns.cpp
@@ -23,9 +23,9 @@ void sp_item_rm_unsatisfied_cns(SPItem &
         g_assert( snappoint_ix < int(snappoints.size()) );
         if (!approx_equal( sp_guide_distance_from_pt(cn.g, snappoints[snappoint_ix].getPoint()), 0) ) {
             remove_last(cn.g->attached_items, SPGuideAttachment(&item, cn.snappoint_ix));
+
             g_assert( i < item.constraints.size() );
-            vector<SPGuideConstraint>::iterator const ei(&item.constraints[i]);
-            item.constraints.erase(ei);
+            item.constraints.erase(item.constraints.begin() + i);
         }
     }
 }
