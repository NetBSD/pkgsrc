$NetBSD: patch-boost_foreach.hpp,v 1.3 2012/07/03 19:46:30 adam Exp $

https://svn.boost.org/trac/boost/ticket/6131

--- boost/foreach.hpp.orig	2012-01-09 15:55:10.000000000 +0000
+++ boost/foreach.hpp
@@ -165,7 +165,7 @@ namespace foreach
 //   this one works on legacy compilers. Overload boost_foreach_is_lightweight_proxy
 //   at the global namespace for your type.
 template<typename T>
-inline boost::foreach::is_lightweight_proxy<T> *
+inline boost::BOOST_FOREACH::is_lightweight_proxy<T> *
 boost_foreach_is_lightweight_proxy(T *&, BOOST_FOREACH_TAG_DEFAULT) { return 0; }
 
 template<typename T>
@@ -190,7 +190,7 @@ boost_foreach_is_lightweight_proxy(T **&
 //   this one works on legacy compilers. Overload boost_foreach_is_noncopyable
 //   at the global namespace for your type.
 template<typename T>
-inline boost::foreach::is_noncopyable<T> *
+inline boost::BOOST_FOREACH::is_noncopyable<T> *
 boost_foreach_is_noncopyable(T *&, BOOST_FOREACH_TAG_DEFAULT) { return 0; }
 
 namespace boost
