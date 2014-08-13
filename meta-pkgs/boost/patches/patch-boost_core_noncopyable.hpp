$NetBSD: patch-boost_core_noncopyable.hpp,v 1.1 2014/08/13 10:56:36 adam Exp $

https://svn.boost.org/trac/boost/ticket/6578

--- boost/core/noncopyable.hpp.orig	2014-07-15 09:08:59.000000000 +0000
+++ boost/core/noncopyable.hpp
@@ -22,7 +22,7 @@ namespace noncopyable_  // protection fr
 {
   class noncopyable
   {
-  protected:
+  public:
 #if !defined(BOOST_NO_CXX11_DEFAULTED_FUNCTIONS) && !defined(BOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS)
       BOOST_CONSTEXPR noncopyable() = default;
       ~noncopyable() = default;
