$NetBSD: patch-src_modules_elliptic.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

commit 81140065318d3ea4171a69c4df0b9a2618d2559c
Author: Karim Belabas <Karim.Belabas@math.u-bordeaux1.fr>
Date:   Mon Nov 29 07:25:40 2010 +0000

    e=ellinit([0,-2675/8,0,118125/16,62015625/16])
    p=[21625/64,-1332375/512
    ellheight(e,p) -> expo overflow due to divrs being called with a t_INT argument


--- src/modules/elliptic.c.orig	2010-02-03 15:04:11.000000000 +0000
+++ src/modules/elliptic.c
@@ -3419,7 +3419,8 @@ ellheight0(GEN e, GEN a, long flag, long
       if (n >= 3*n2) { u = n2; v = 3; } else { u = n; v = 8; }
     }
     /* z -= u log(p) / v */
-    z = gadd(z, divrs(mulsr(-u, glog(p,prec)), v));
+    if (u)
+      z = gadd(z, divrs(mulsr(-u, glog(p,prec)), v));
   }
   return gerepileupto(av, gmul2n(z, 1));
 }
