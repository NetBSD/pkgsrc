$NetBSD: patch-modules_contrib_src_chamfermatching.cpp,v 1.1 2018/02/16 17:13:58 wiz Exp $

Address of variable is never NULL; some compilers error out about this.

--- modules/contrib/src/chamfermatching.cpp.orig	2015-02-25 12:10:31.000000000 +0000
+++ modules/contrib/src/chamfermatching.cpp
@@ -966,10 +966,8 @@ void ChamferMatcher::Matching::computeDi
     for (int y=0;y<h;++y) {
         for (int x=0;x<w;++x) {
             // initialize
-            if (&annotate_img!=NULL) {
                 annotate_img.at<Vec2i>(y,x)[0]=x;
                 annotate_img.at<Vec2i>(y,x)[1]=y;
-            }
 
             uchar edge_val = edges_img.at<uchar>(y,x);
             if( (edge_val!=0) ) {
@@ -1013,10 +1011,8 @@ void ChamferMatcher::Matching::computeDi
                 dist_img.at<float>(ny,nx) = dist;
                 q.push(std::make_pair(nx,ny));
 
-                if (&annotate_img!=NULL) {
                     annotate_img.at<Vec2i>(ny,nx)[0]=annotate_img.at<Vec2i>(y,x)[0];
                     annotate_img.at<Vec2i>(ny,nx)[1]=annotate_img.at<Vec2i>(y,x)[1];
-                }
             }
         }
     }
@@ -1108,7 +1104,6 @@ ChamferMatcher::Match* ChamferMatcher::M
     float cost = (sum_distance/truncate_)/addr.size();
 
 
-    if (&orientation_img!=NULL) {
         float* optr = orientation_img.ptr<float>(y)+x;
         float sum_orientation = 0;
         int cnt_orientation = 0;
@@ -1127,7 +1122,6 @@ ChamferMatcher::Match* ChamferMatcher::M
                         cost = (float)(beta*cost+alpha*(sum_orientation/(2*CV_PI))/cnt_orientation);
         }
 
-    }
 
     if(cost > 0){
         ChamferMatcher::Match* istance = new ChamferMatcher::Match();
