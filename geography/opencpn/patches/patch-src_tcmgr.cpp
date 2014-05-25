$NetBSD: patch-src_tcmgr.cpp,v 1.1 2014/05/25 18:26:57 bouyer Exp $
64bit time_t fix

--- src/tcmgr.cpp.orig	2014-05-23 17:16:52.000000000 +0200
+++ src/tcmgr.cpp	2014-05-23 17:18:08.000000000 +0200
@@ -569,7 +569,7 @@
         f += fact * w[n] * (fr[deriv-n] - fl[deriv-n]);
         fact *= (double)(deriv - n)/(n+1) * (1.0/TIDE_BLEND_TIME);
     }
-    printf(" %ld  %g     %g %g %g\n", t, blend, fr[0], fl[0], f);
+    printf(" %ld  %g     %g %g %g\n", (long)t, blend, fr[0], fl[0], f);
     return f;
 }
 
