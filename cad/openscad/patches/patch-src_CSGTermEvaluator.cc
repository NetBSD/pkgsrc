$NetBSD: patch-src_CSGTermEvaluator.cc,v 1.1 2019/06/03 15:22:51 bouyer Exp $

--- src/CSGTermEvaluator.cc.orig	2019-06-03 15:20:25.276227139 +0200
+++ src/CSGTermEvaluator.cc	2019-06-03 15:21:19.026127066 +0200
@@ -109,8 +109,7 @@
 			shared_ptr<const PolySet> ps = dynamic_pointer_cast<const PolySet>(geom);
 			// Since is_convex() doesn't handle non-planar faces, we need to tessellate
 			// also in the indeterminate state so we cannot just use a boolean comparison. See #1061
-			bool convex = ps->convexValue();
-			if (ps && !convex) {
+			if (ps && !ps->convexValue()) {
 				assert(ps->getDimension() == 3);
 				PolySet *ps_tri = new PolySet(3, ps->convexValue());
 				ps_tri->setConvexity(ps->getConvexity());
