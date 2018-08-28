$NetBSD: patch-common_fracsubr.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/fracsubr.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/fracsubr.c
@@ -352,8 +352,8 @@ init_restart:
 
    if(fractype != CELLULAR && fractype != ANT)  /* fudgetolong fails w >10 digits in double */
    {
-      creal = fudgetolong(param[0]); /* integer equivs for it all */
-      cimag = fudgetolong(param[1]);
+      my_creal = fudgetolong(param[0]); /* integer equivs for it all */
+      my_cimag = fudgetolong(param[1]);
       xmin  = fudgetolong(xxmin);
       xmax  = fudgetolong(xxmax);
       x3rd  = fudgetolong(xx3rd);
