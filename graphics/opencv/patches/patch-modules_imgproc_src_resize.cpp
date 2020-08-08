$NetBSD: patch-modules_imgproc_src_resize.cpp,v 1.1 2020/08/08 22:40:59 joerg Exp $

On Illumos int8_t != ET, so be explicit about the cast to be used here.

--- modules/imgproc/src/resize.cpp.orig	2020-08-08 22:04:15.259991576 +0000
+++ modules/imgproc/src/resize.cpp
@@ -652,7 +652,7 @@ template <typename ET, typename FT>
 void vlineSet(FT* src, ET* dst, int dst_width)
 {
     for (int i = 0; i < dst_width; i++)
-        dst[i] = src[i];
+        dst[i] = int8_t(src[i]);
 }
 template <>
 void vlineSet<uint8_t, ufixedpoint16>(ufixedpoint16* src, uint8_t* dst, int dst_width)
@@ -684,7 +684,7 @@ void vlineResize(FT* src, size_t src_ste
         typename FT::WT res = src[i] * m[0];
         for (int k = 1; k < n; k++)
             res = res + src[i + k*src_step] * m[k];
-        dst[i] = res;
+        dst[i] = int8_t(res);
     }
 }
 template <>
