$NetBSD: patch-src_gd.h,v 1.1 2021/09/19 19:25:14 prlw1 Exp $

Revert "Fix #318, these macros are not used as planed, we have
separate functions for each.
https://github.com/libgd/libgd/commit/f4bc1f5c26925548662946ed7cfa473c190a104a

--- src/gd.h.orig	2021-09-11 04:52:47.000000000 +0000
+++ src/gd.h
@@ -1604,6 +1604,11 @@ BGD_DECLARE(void) gdImageFlipHorizontal(
 BGD_DECLARE(void) gdImageFlipVertical(gdImagePtr im);
 BGD_DECLARE(void) gdImageFlipBoth(gdImagePtr im);
 
+#define GD_FLIP_HORINZONTAL 1 /* typo, kept for BC */
+#define GD_FLIP_HORIZONTAL 1
+#define GD_FLIP_VERTICAL 2
+#define GD_FLIP_BOTH 3
+
 /**
  * Group: Crop
  *
