$NetBSD: patch-boost_noncopyable.hpp,v 1.1 2013/11/20 19:17:55 adam Exp $

https://svn.boost.org/trac/boost/ticket/6578

--- boost/noncopyable.hpp.orig	2013-11-20 14:20:55.000000000 +0000
+++ boost/noncopyable.hpp
@@ -22,7 +22,7 @@ namespace noncopyable_  // protection fr
 {
   class noncopyable
   {
-   protected:
+   public:
 #ifndef BOOST_NO_DEFAULTED_FUNCTIONS
     BOOST_CONSTEXPR noncopyable() = default;
     ~noncopyable() = default;
