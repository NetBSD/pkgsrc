$NetBSD: patch-boost_functional_hash_hash.hpp,v 1.1 2012/08/31 12:20:56 adam Exp $

Allow hashing enums.

--- boost/functional/hash/hash.hpp.orig	2012-07-15 23:28:30.000000000 +0000
+++ boost/functional/hash/hash.hpp
@@ -15,6 +15,8 @@
 #include <boost/functional/hash/detail/hash_float.hpp>
 #include <string>
 #include <boost/limits.hpp>
+#include <boost/type_traits/is_enum.hpp>
+#include <boost/utility/enable_if.hpp>
 
 #if defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
 #include <boost/type_traits/is_pointer.hpp>
@@ -90,6 +92,10 @@ namespace boost
     template <typename T>
     typename boost::hash_detail::ulong_numbers<T>::type hash_value(T);
 
+    template <typename T>
+    typename boost::enable_if<boost::is_enum<T>, std::size_t>::type
+    	hash_value(T);
+
 #if !BOOST_WORKAROUND(__DMC__, <= 0x848)
     template <class T> std::size_t hash_value(T* const&);
 #else
@@ -179,6 +185,13 @@ namespace boost
         return hash_detail::hash_value_unsigned(v);
     }
 
+    template <typename T>
+    typename boost::enable_if<boost::is_enum<T>, std::size_t>::type
+    	hash_value(T v)
+    {
+    	return static_cast<std::size_t>(v);
+    }
+
     // Implementation by Alberto Barbati and Dave Harris.
 #if !BOOST_WORKAROUND(__DMC__, <= 0x848)
     template <class T> std::size_t hash_value(T* const& v)
