$NetBSD: patch-common_video_iso-mpeg4_include_basic.hpp,v 1.1 2017/05/06 18:12:00 maya Exp $

libstdc++6 disapproves of lowercase min,max macros
use uppercase.

--- common/video/iso-mpeg4/include/basic.hpp.orig	2005-05-09 21:29:45.000000000 +0000
+++ common/video/iso-mpeg4/include/basic.hpp
@@ -89,11 +89,11 @@ Revision History:
 #define transpPixel CPixel(0,0,0,0)
 #define opaquePixel CPixel(255,255,255,255)
 
-#ifndef max
-#define max(a,b) (((a) > (b)) ? (a) : (b))
+#ifndef MAX
+#define MAX(a,b) (((a) > (b)) ? (a) : (b))
 #endif
-#ifndef min
-#define min(a, b)  (((a) < (b)) ? (a) : (b))
+#ifndef MIN
+#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
 #endif
 #define signOf(x) (((x) > 0) ? 1 : 0)
 #define invSignOf(x) ((x) > 0 ? 0 : 1)					// see p.22/H.263
