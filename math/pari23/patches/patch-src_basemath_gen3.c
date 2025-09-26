$NetBSD: patch-src_basemath_gen3.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

commit a0a089fd44e252c5ec535dd17b73f297f2e18ecd
Author: Bill Allombert <Bill.Allombert@math.u-bordeaux1.fr>
Date:   Wed Mar 17 10:55:35 2010 +0000

    precision(0.E100) returned an invalid object.                     [F164]

--- src/basemath/gen3.c.orig	2009-09-24 09:47:52.000000000 +0000
+++ src/basemath/gen3.c
@@ -199,7 +199,7 @@ GEN
 ggprecision(GEN x)
 {
   long a = gprecision(x);
-  return utoipos(a ? prec2ndec(a): VERYBIGINT);
+  return utoi(a ? prec2ndec(a): VERYBIGINT);
 }
 
 GEN
