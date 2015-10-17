$NetBSD: patch-modules_core_include_opencv2_core_types_c.h,v 1.1 2015/10/17 10:28:43 fhajny Exp $

Define 'depth' as unsigned int, or IPL_DEPTH_SIGN=0x8000000 won't fit in int.

--- modules/core/include/opencv2/core/types_c.h.orig	2012-12-07 21:15:58.000000000 +0000
+++ modules/core/include/opencv2/core/types_c.h
@@ -473,7 +473,7 @@ typedef struct _IplImage
     int  ID;                /* version (=0)*/
     int  nChannels;         /* Most of OpenCV functions support 1,2,3 or 4 channels */
     int  alphaChannel;      /* Ignored by OpenCV */
-    int  depth;             /* Pixel depth in bits: IPL_DEPTH_8U, IPL_DEPTH_8S, IPL_DEPTH_16S,
+    unsigned int  depth;             /* Pixel depth in bits: IPL_DEPTH_8U, IPL_DEPTH_8S, IPL_DEPTH_16S,
                                IPL_DEPTH_32S, IPL_DEPTH_32F and IPL_DEPTH_64F are supported.  */
     char colorModel[4];     /* Ignored by OpenCV */
     char channelSeq[4];     /* ditto */
