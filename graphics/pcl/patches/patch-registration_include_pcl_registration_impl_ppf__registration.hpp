$NetBSD: patch-registration_include_pcl_registration_impl_ppf__registration.hpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- registration/include/pcl/registration/impl/ppf_registration.hpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ registration/include/pcl/registration/impl/ppf_registration.hpp
@@ -84,7 +84,9 @@ pcl::PPFRegistration<PointSource, PointT
   PoseWithVotesList voted_poses;
   // Consider every <scene_reference_point_sampling_rate>-th point as the reference point => fix s_r
   float f1, f2, f3, f4;
-  for (std::size_t scene_reference_index = 0; scene_reference_index < target_->size (); scene_reference_index += scene_reference_point_sampling_rate_)
+  for (index_t scene_reference_index = 0;
+       scene_reference_index < static_cast<index_t>(target_->size());
+       scene_reference_index += scene_reference_point_sampling_rate_)
   {
     Eigen::Vector3f scene_reference_point = (*target_)[scene_reference_index].getVector3fMap (),
         scene_reference_normal = (*target_)[scene_reference_index].getNormalVector3fMap ();
