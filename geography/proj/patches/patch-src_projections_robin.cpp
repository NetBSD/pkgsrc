$NetBSD: patch-src_projections_robin.cpp,v 1.1 2025/04/27 00:23:07 gdt Exp $

Fix bare isnan and math includes.   Cherry-picked from pending upstream PR.

https://github.com/OSGeo/PROJ/pull/4471

--- src/projections/robin.cpp.orig	2025-04-27 00:09:12.308976595 +0000
+++ src/projections/robin.cpp
@@ -1,7 +1,7 @@
 
 #include "proj.h"
 #include "proj_internal.h"
-#include <math.h>
+#include <cmath>
 
 PROJ_HEAD(robin, "Robinson") "\n\tPCyl, Sph";
 
@@ -82,7 +82,7 @@ static PJ_XY robin_s_forward(PJ_LP lp, P
     (void)P;
 
     dphi = fabs(lp.phi);
-    i = isnan(lp.phi) ? -1 : lround(floor(dphi * C1 + 1e-15));
+    i = std::isnan(lp.phi) ? -1 : lround(floor(dphi * C1 + 1e-15));
     if (i < 0) {
         proj_errno_set(P, PROJ_ERR_COORD_TRANSFM_OUTSIDE_PROJECTION_DOMAIN);
         return xy;
@@ -116,7 +116,7 @@ static PJ_LP robin_s_inverse(PJ_XY xy, P
         }
     } else { /* general problem */
         /* in Y space, reduce to table interval */
-        long i = isnan(lp.phi) ? -1 : lround(floor(lp.phi * NODES));
+        long i = std::isnan(lp.phi) ? -1 : lround(floor(lp.phi * NODES));
         if (i < 0 || i >= NODES) {
             proj_errno_set(P, PROJ_ERR_COORD_TRANSFM_OUTSIDE_PROJECTION_DOMAIN);
             return lp;
