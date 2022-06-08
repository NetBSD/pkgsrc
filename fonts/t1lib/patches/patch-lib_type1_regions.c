$NetBSD: patch-lib_type1_regions.c,v 1.1 2022/06/08 19:00:13 chuck Exp $

Fixed incorrect calculation of ceiling that results in t1lib LONGCOPY
writing past the end of a malloc buffer.   Corrects crash on OSX
and resolves complaints from the address sanitizer.

--- lib/type1/regions.c.orig	2022-06-08 13:28:23.000000000 -0400
+++ lib/type1/regions.c	2022-06-08 13:28:31.000000000 -0400
@@ -340,7 +340,8 @@
 longs.  The destination must be able to hold these extra bytes because
 Allocate() makes everything it allocates be in multiples of longs.
 */
-       LONGCOPY(&r[1], xvalues, (ymax - iy) * sizeof(pel) + sizeof(LONG) - 1);
+       LONGCOPY(&r[1], xvalues,
+         ((ymax - iy) * sizeof(pel) + sizeof(LONG) - 1) & ~(sizeof(LONG) - 1));
  
        IfTrace1((RegionDebug),"result=%p\n", r);
        return(r);
