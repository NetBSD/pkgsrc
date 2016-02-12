$NetBSD: patch-include_mdds_point__quad__tree.hpp,v 1.1 2016/02/12 13:34:45 wiz Exp $

--- include/mdds/point_quad_tree.hpp.orig	2015-06-11 23:53:55.000000000 +0000
+++ include/mdds/point_quad_tree.hpp
@@ -635,10 +635,10 @@ point_quad_tree<_Key,_Data>::~point_quad
 template<typename _Key, typename _Data>
 void point_quad_tree<_Key,_Data>::insert(key_type x, key_type y, data_type data)
 {
-    m_xrange.first  = ::std::min(m_xrange.first,  x);
-    m_xrange.second = ::std::max(m_xrange.second, x);
-    m_yrange.first  = ::std::min(m_yrange.first,  y);
-    m_yrange.second = ::std::max(m_yrange.second, y);
+    m_xrange.first  = (::std::min)(m_xrange.first,  x);
+    m_xrange.second = (::std::max)(m_xrange.second, x);
+    m_yrange.first  = (::std::min)(m_yrange.first,  y);
+    m_yrange.second = (::std::max)(m_yrange.second, y);
 
     if (!m_root)
     {
