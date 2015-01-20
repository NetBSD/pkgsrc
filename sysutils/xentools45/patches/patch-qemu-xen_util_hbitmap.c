$NetBSD: patch-qemu-xen_util_hbitmap.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

conflits with the popcountl from <strings.h>, no need to redefine one.

--- qemu-xen/util/hbitmap.c.orig	2015-01-19 16:33:58.000000000 +0100
+++ qemu-xen/util/hbitmap.c	2015-01-19 16:40:45.000000000 +0100
@@ -92,11 +92,6 @@
     unsigned long *levels[HBITMAP_LEVELS];
 };
 
-static inline int popcountl(unsigned long l)
-{
-    return BITS_PER_LONG == 32 ? ctpop32(l) : ctpop64(l);
-}
-
 /* Advance hbi to the next nonzero word and return it.  hbi->pos
  * is updated.  Returns zero if we reach the end of the bitmap.
  */
