$NetBSD: patch-src_tcmgr.cpp,v 1.2 2015/01/22 12:34:15 bouyer Exp $

64bit time_t fix
Reported in FS#1403

--- src/tcmgr.cpp.orig	2014-05-26 21:26:36.000000000 +0200
+++ src/tcmgr.cpp	2014-05-26 21:30:22.000000000 +0200
@@ -518,7 +518,7 @@
         f += fact * w[n] * (fr[deriv-n] - fl[deriv-n]);
         fact *= (double)(deriv - n)/(n+1) * (1.0/TIDE_BLEND_TIME);
     }
-    printf(" %ld  %g     %g %g %g\n", t, blend, fr[0], fl[0], f);
+    printf(" %ld  %g     %g %g %g\n", (long)t, blend, fr[0], fl[0], f);
     return f;
 }
 
