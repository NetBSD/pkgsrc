$NetBSD: patch-boost_archive_basic__archive.hpp,v 1.4 2021/01/01 08:19:02 ryoon Exp $

--- boost/archive/basic_archive.hpp.orig	2020-08-11 14:56:51.000000000 +0000
+++ boost/archive/basic_archive.hpp
@@ -82,7 +82,7 @@ public:
     explicit class_id_type(const int t_) : t(t_){
         BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
     }
-    explicit class_id_type(const std::size_t t_) : t(t_){
+    explicit class_id_type(const size_t t_) : t(t_){
  //       BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
     }
     class_id_type(const class_id_type & t_) :
@@ -119,7 +119,7 @@ public:
     object_id_type(): t(0) {}
     // note: presumes that size_t >= unsigned int.
     // use explicit cast to silence useless warning
-    explicit object_id_type(const std::size_t & t_) : t(static_cast<base_type>(t_)){
+    explicit object_id_type(const size_t & t_) : t(static_cast<base_type>(t_)){
         // make quadruple sure that we haven't lost any real integer
         // precision
         BOOST_ASSERT(t_ <= boost::integer_traits<base_type>::const_max);
