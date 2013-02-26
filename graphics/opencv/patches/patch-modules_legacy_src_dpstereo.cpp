$NetBSD: patch-modules_legacy_src_dpstereo.cpp,v 1.1 2013/02/26 23:38:08 joerg Exp $

--- modules/legacy/src/dpstereo.cpp.orig	2012-10-22 22:55:11.000000000 +0000
+++ modules/legacy/src/dpstereo.cpp
@@ -65,6 +65,8 @@
 
 #define ICV_MAX_DP_SUM_VAL (INT_MAX/4)
 
+#include <algorithm>
+
 typedef struct _CvDPCell
 {
     uchar  step; //local-optimal step
@@ -76,8 +78,8 @@ typedef struct _CvRightImData
     uchar min_val, max_val;
 } _CvRightImData;
 
-#define CV_IMAX3(a,b,c) ((temp3 = (a) >= (b) ? (a) : (b)),(temp3 >= (c) ? temp3 : (c)))
-#define CV_IMIN3(a,b,c) ((temp3 = (a) <= (b) ? (a) : (b)),(temp3 <= (c) ? temp3 : (c)))
+#define CV_IMAX3(a,b,c) std::max((a), std::max((b), (c)))
+#define CV_IMIN3(a,b,c) std::min((a), std::min((b), (c)))
 
 static void icvFindStereoCorrespondenceByBirchfieldDP( uchar* src1, uchar* src2,
                                                 uchar* disparities,
