$NetBSD: patch-src_live__effects_lpe-perp__bisector.h,v 1.1 2014/01/11 17:48:52 wiz Exp $

Fix compilation with clang/libc++.

--- src/live_effects/lpe-perp_bisector.h.orig	2011-07-08 18:25:09.000000000 +0000
+++ src/live_effects/lpe-perp_bisector.h
@@ -27,7 +27,7 @@ namespace PB {
   class KnotHolderEntityEnd;
   class KnotHolderEntityLeftEnd;
   class KnotHolderEntityRightEnd;
-  void bisector_end_set(SPItem *item, Geom::Point const &p, bool left);
+  void bisector_end_set(SPItem *item, Geom::Point const &p, bool left = true);
 }
 
 class LPEPerpBisector : public Effect {
@@ -46,7 +46,7 @@ public:
     friend class PB::KnotHolderEntityEnd;
     friend class PB::KnotHolderEntityLeftEnd;
     friend class PB::KnotHolderEntityRightEnd;
-    friend void PB::bisector_end_set(SPItem *item, Geom::Point const &p, bool left = true);
+    friend void PB::bisector_end_set(SPItem *item, Geom::Point const &p, bool left);
 
 private:
     ScalarParam length_left;
