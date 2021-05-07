$NetBSD: patch-registration_include_pcl_registration_ppf__registration.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- registration/include/pcl/registration/ppf_registration.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ registration/include/pcl/registration/ppf_registration.h
@@ -260,7 +260,7 @@ namespace pcl
       PPFHashMapSearch::Ptr search_method_;
 
       /** \brief parameter for the sampling rate of the scene reference points */
-      unsigned int scene_reference_point_sampling_rate_;
+     uindex_t  scene_reference_point_sampling_rate_;
 
       /** \brief position and rotation difference thresholds below which two
         * poses are considered to be in the same cluster (for the clustering phase of the algorithm) */
