$NetBSD: patch-boost_archive_basic__archive.hpp,v 1.3 2020/05/06 13:33:53 adam Exp $

--- boost/archive/basic_archive.hpp.orig	2020-04-22 13:35:57.000000000 +0000
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
@@ -152,7 +152,7 @@ public:
     object_id_type(): t(0) {};
     // note: presumes that size_t >= unsigned int.
     // use explicit cast to silence useless warning
-    explicit object_id_type(const std::size_t & t_) : t(static_cast<base_type>(t_)){
+    explicit object_id_type(const size_t & t_) : t(static_cast<base_type>(t_)){
         // make quadriple sure that we haven't lost any real integer
         // precision
         BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
