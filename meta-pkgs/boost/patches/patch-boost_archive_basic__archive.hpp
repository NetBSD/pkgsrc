$NetBSD: patch-boost_archive_basic__archive.hpp,v 1.1 2017/08/24 19:31:32 adam Exp $

--- boost/archive/basic_archive.hpp.orig	2012-08-27 07:38:03.000000000 +0000
+++ boost/archive/basic_archive.hpp
@@ -115,7 +115,7 @@ public:
     explicit class_id_type(const int t_) : t(t_){
         BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
     }
-    explicit class_id_type(const std::size_t t_) : t(t_){
+    explicit class_id_type(const size_t t_) : t(t_){
  //       BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
     }
     class_id_type(const class_id_type & t_) : 
@@ -151,7 +151,7 @@ private:
 public:
     object_id_type(): t(0) {};
     // note: presumes that size_t >= unsigned int.
-    explicit object_id_type(const std::size_t & t_) : t(t_){
+    explicit object_id_type(const size_t & t_) : t(t_){
         BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
     }
     object_id_type(const object_id_type & t_) : 
