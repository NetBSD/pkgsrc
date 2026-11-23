$NetBSD: patch-src_gallium_auxiliary_vl_vl__csc.c,v 1.1 2026/11/23 10:29:52 adam Exp $

Fix error: macro "memcpy" passed 15 arguments, but takes just 3.

--- src/gallium/auxiliary/vl/vl_csc.c.orig	2026-09-02 14:43:54.278607333 +0000
+++ src/gallium/auxiliary/vl/vl_csc.c
@@ -192,20 +192,22 @@ void vl_csc_get_primaries_matrix(enum pipe_video_vpp_c
    case PIPE_VIDEO_VPP_PRI_SMPTE240M:
       switch (out_color_primaries) {
       case PIPE_VIDEO_VPP_PRI_BT2020:
-         memcpy(matrix, &(vl_csc_matrix){
+         vl_csc_matrix m1 = {
             { 0.595254, 0.349314, 0.055432, 0.0 },
             { 0.081244, 0.891503, 0.027253, 0.0 },
             { 0.015512, 0.081912, 0.902576, 0.0 },
-         }, sizeof(vl_csc_matrix));
+         };
+         memcpy(matrix, &m1, sizeof(vl_csc_matrix));
          break;
 
       case PIPE_VIDEO_VPP_PRI_BT709:
       default:
-         memcpy(matrix, &(vl_csc_matrix){
+         vl_csc_matrix m2 = {
             {  0.939543,  0.050181, 0.010276, 0.0 },
             {  0.017772,  0.965793, 0.016435, 0.0 },
             { -0.001622, -0.004370, 1.005991, 0.0 },
-         }, sizeof(vl_csc_matrix));
+         };
+         memcpy(matrix, &m2, sizeof(vl_csc_matrix));
          break;
       }
       break;
@@ -214,20 +216,22 @@ void vl_csc_get_primaries_matrix(enum pipe_video_vpp_c
       switch (out_color_primaries) {
       case PIPE_VIDEO_VPP_PRI_SMPTE170M:
       case PIPE_VIDEO_VPP_PRI_SMPTE240M:
-         memcpy(matrix, &(vl_csc_matrix){
+         vl_csc_matrix m3 = {
             {  1.776133, -0.687820, -0.088313, 0.0 },
             { -0.161375,  1.187315, -0.025940, 0.0 },
             { -0.015881, -0.095931,  1.111812, 0.0 },
-         }, sizeof(vl_csc_matrix));
+         };
+         memcpy(matrix, &m3, sizeof(vl_csc_matrix));
          break;
 
       case PIPE_VIDEO_VPP_PRI_BT709:
       default:
-         memcpy(matrix, &(vl_csc_matrix){
+         vl_csc_matrix m4 = {
             {  1.660491, -0.587641, -0.072850, 0.0 },
             { -0.124550,  1.132900, -0.008349, 0.0 },
             { -0.018151, -0.100579,  1.118729, 0.0 },
-         }, sizeof(vl_csc_matrix));
+         };
+         memcpy(matrix, &m4, sizeof(vl_csc_matrix));
          break;
       }
       break;
@@ -237,19 +241,21 @@ void vl_csc_get_primaries_matrix(enum pipe_video_vpp_c
       switch (out_color_primaries) {
       case PIPE_VIDEO_VPP_PRI_SMPTE170M:
       case PIPE_VIDEO_VPP_PRI_SMPTE240M:
-         memcpy(matrix, &(vl_csc_matrix){
+         vl_csc_matrix m5 = {
             {  1.065379, -0.055401, -0.009978, 0.0 },
             { -0.019633,  1.036363, -0.016731, 0.0 },
             {  0.001632,  0.004412,  0.993956, 0.0 },
-         }, sizeof(vl_csc_matrix));
+         };
+         memcpy(matrix, &m5, sizeof(vl_csc_matrix));
          break;
 
       case PIPE_VIDEO_VPP_PRI_BT2020:
-         memcpy(matrix, &(vl_csc_matrix){
+         vl_csc_matrix m6 = {
             { 0.627404, 0.329283, 0.043313, 0.0 },
             { 0.069097, 0.919540, 0.011362, 0.0 },
             { 0.016391, 0.088013, 0.895595, 0.0 },
-         }, sizeof(vl_csc_matrix));
+         };
+         memcpy(matrix, &m6, sizeof(vl_csc_matrix));
          break;
 
       default:
