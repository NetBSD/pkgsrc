$NetBSD: patch-jbig2__image.c,v 1.1 2017/08/05 08:03:05 nros Exp $
* fix CVE-2017-7976
  fixed upstream so remove this patch on the next version update
--- jbig2_image.c.orig	2017-08-05 07:31:46.000000000 +0000
+++ jbig2_image.c
@@ -256,7 +256,8 @@ jbig2_image_compose(Jbig2Ctx *ctx, Jbig2
     /* general OR case */
     s = ss;
     d = dd = dst->data + y * dst->stride + leftbyte;
-    if (d < dst->data || leftbyte > dst->stride || h * dst->stride < 0 || d - leftbyte + h * dst->stride > dst->data + dst->height * dst->stride) {
+    if (d < dst->data || leftbyte > dst->stride || h * dst->stride < 0 || d - leftbyte + h * dst->stride > dst->data + dst->height * dst->stride ||
+        s - leftbyte + (h - 1) * src->stride + rightbyte > src->data + src->height * src->stride) {
         return jbig2_error(ctx, JBIG2_SEVERITY_FATAL, -1, "preventing heap overflow in jbig2_image_compose");
     }
     if (leftbyte == rightbyte) {
