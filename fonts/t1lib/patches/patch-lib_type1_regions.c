$NetBSD: patch-lib_type1_regions.c,v 1.2 2024/12/05 08:21:53 markd Exp $

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
@@ -604,6 +605,7 @@ void ChangeDirection(type, R, x, y, dy,
        register struct region *R;  /* region in which we are changing direction */
        fractpel x,y;         /* current beginning x,y                        */
        fractpel dy;          /* direction and magnitude of change in y       */
+       fractpel x2,y2;
 {
        register fractpel ymin,ymax;  /* minimum and maximum Y since last call */
        register fractpel x_at_ymin,x_at_ymax;  /* their respective X's       */
