$NetBSD: patch-boost_foreach_fwd.hpp,v 1.3 2012/07/03 19:46:30 adam Exp $

https://svn.boost.org/trac/boost/ticket/6131

--- boost/foreach_fwd.hpp.orig	2012-01-09 15:58:44.000000000 +0000
+++ boost/foreach_fwd.hpp
@@ -14,6 +14,8 @@
 #ifndef BOOST_FOREACH_FWD_HPP
 #define BOOST_FOREACH_FWD_HPP
 
+#include <utility> // for std::pair
+
 // This must be at global scope, hence the uglified name
 enum boost_foreach_argument_dependent_lookup_hack
 {
@@ -25,6 +27,9 @@ namespace boost
 
 namespace foreach
 {
+    template<typename T>
+    std::pair<T, T> in_range(T begin, T end);
+
     ///////////////////////////////////////////////////////////////////////////////
     // boost::foreach::tag
     //
@@ -46,6 +51,22 @@ namespace foreach
 
 } // namespace foreach
 
+namespace BOOST_FOREACH
+{
+    using foreach::in_range;
+    using foreach::tag;
+
+    template<typename T>
+    struct is_lightweight_proxy
+      : foreach::is_lightweight_proxy<T>
+    {};
+
+    template<typename T>
+    struct is_noncopyable
+      : foreach::is_noncopyable<T>
+    {};
+} // namespace BOOST_FOREACH
+
 } // namespace boost
 
 #endif
