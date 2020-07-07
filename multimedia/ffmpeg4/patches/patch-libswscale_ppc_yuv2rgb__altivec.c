$NetBSD: patch-libswscale_ppc_yuv2rgb__altivec.c,v 1.1 2020/07/07 09:23:06 rin Exp $

Fix build for powerpc machines that have AltiVec but no VSX support.

Workaround for upstream commit 3a557c5d88b7b15b5954ba2743febb055549b536:
https://github.com/FFmpeg/FFmpeg/commit/3a557c5d88b7b15b5954ba2743febb055549b536

--- libswscale/ppc/yuv2rgb_altivec.c.orig	2020-06-16 03:54:24.000000000 +0900
+++ libswscale/ppc/yuv2rgb_altivec.c	2020-07-07 17:01:02.342931087 +0900
@@ -283,6 +283,23 @@ static inline void cvtyuvtoRGB(SwsContex
  * ------------------------------------------------------------------------------
  */
 
+#if HAVE_VSX
+static inline vector unsigned char ffmpeg_vec_xl(const ubyte *xi)
+{
+    return vec_xl(0, xi)
+}
+#else
+static inline vector unsigned char ffmpeg_vec_xl(const ubyte *xi)
+{
+    const vector unsigned char *xivP;
+    vector unsigned char align_perm;
+
+    xivP = (const vector unsigned char *) xi;
+    align_perm = vec_lvsl(0, xi);
+    return (vector unsigned char) vec_perm(xivP[0], xivP[1], align_perm);
+}
+#endif
+
 #define DEFCSP420_CVT(name, out_pixels)                                       \
 static int altivec_ ## name(SwsContext *c, const unsigned char **in,          \
                             int *instrides, int srcSliceY, int srcSliceH,     \
@@ -335,13 +352,13 @@ static int altivec_ ## name(SwsContext *
         vec_dstst(oute, (0x02000002 | (((w * 3 + 32) / 32) << 16)), 1);       \
                                                                               \
         for (j = 0; j < w / 16; j++) {                                        \
-            y0 = vec_xl(0, y1i);                                              \
+            y0 = ffmpeg_vec_xl(y1i);                                          \
                                                                               \
-            y1 = vec_xl(0, y2i);                                              \
+            y1 = ffmpeg_vec_xl(y2i);                                          \
                                                                               \
-            u = (vector signed char) vec_xl(0, ui);                           \
+            u = (vector signed char) ffmpeg_vec_xl(ui);                       \
                                                                               \
-            v = (vector signed char) vec_xl(0, vi);                           \
+            v = (vector signed char) ffmpeg_vec_xl(vi);                       \
                                                                               \
             u = (vector signed char)                                          \
                     vec_sub(u,                                                \
