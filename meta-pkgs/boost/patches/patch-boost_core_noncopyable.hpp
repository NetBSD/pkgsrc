$NetBSD: patch-boost_core_noncopyable.hpp,v 1.2 2018/12/13 19:22:57 adam Exp $

https://svn.boost.org/trac/boost/ticket/6578

--- boost/core/noncopyable.hpp.orig	2018-12-05 19:58:16.000000000 +0000
+++ boost/core/noncopyable.hpp
@@ -37,7 +37,7 @@ namespace noncopyable_  // protection fr
 
   class noncopyable: base_token
   {
-  protected:
+  public:
 #if !defined(BOOST_NO_CXX11_DEFAULTED_FUNCTIONS) && !defined(BOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS)
       BOOST_CONSTEXPR noncopyable() = default;
       ~noncopyable() = default;
