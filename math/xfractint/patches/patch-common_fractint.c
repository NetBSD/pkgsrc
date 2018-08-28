$NetBSD: patch-common_fractint.c,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- common/fractint.c.orig	2014-05-03 13:12:35.000000000 +0000
+++ common/fractint.c
@@ -95,7 +95,7 @@ int compiled_by_turboc = 0;
 
         int     fractype;               /* if == 0, use Mandelbrot  */
         char    stdcalcmode;            /* '1', '2', 'g', 'b'       */
-        long    creal, cimag;           /* real, imag'ry parts of C */
+        long    my_creal, my_cimag;     /* real, imag'ry parts of C */
         long    delx, dely;             /* screen pixel increments  */
         long    delx2, dely2;           /* screen pixel increments  */
         LDBL    delxx, delyy;           /* screen pixel increments  */
