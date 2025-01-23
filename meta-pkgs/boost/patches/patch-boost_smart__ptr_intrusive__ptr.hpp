$NetBSD: patch-boost_smart__ptr_intrusive__ptr.hpp,v 1.1 2025/01/23 20:56:00 wiz Exp $

Fix operator<< for shared_ptr and intrusive_ptr.
https://github.com/boostorg/smart_ptr/commit/e7433ba54596da97cb7859455cd37ca140305a9c

--- boost/smart_ptr/intrusive_ptr.hpp.orig	2024-12-05 00:53:36.000000000 +0000
+++ boost/smart_ptr/intrusive_ptr.hpp
@@ -285,7 +285,7 @@ template<class T, class U> intrusive_ptr
 
 // operator<<
 
-template<class Y> std::ostream & operator<< (std::ostream & os, intrusive_ptr<Y> const & p)
+template<class E, class T, class Y> std::basic_ostream<E, T> & operator<< (std::basic_ostream<E, T> & os, intrusive_ptr<Y> const & p)
 {
     os << p.get();
     return os;
