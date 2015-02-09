$NetBSD: patch-share_solid__draw.h,v 1.1 2015/02/09 09:02:12 snj Exp $

NetBSD's limits.h defines a PASS_MAX.

--- share/solid_draw.h.orig	2015-01-07 23:09:04.000000000 -0800
+++ share/solid_draw.h	2015-01-07 23:09:52.000000000 -0800
@@ -28,6 +28,8 @@
 
 /* Named rendering pass indices. */
 
+#undef PASS_MAX
+
 enum
 {
     PASS_OPAQUE = 0,
