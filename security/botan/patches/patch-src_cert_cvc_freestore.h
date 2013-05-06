$NetBSD: patch-src_cert_cvc_freestore.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/cert/cvc/freestore.h.orig	2013-04-30 22:56:51.000000000 +0000
+++ src/cert/cvc/freestore.h
@@ -8,7 +8,9 @@
 
 #include <botan/build.h>
 
-#if defined(BOTAN_USE_STD_TR1)
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  #include <memory>
+#elif defined(BOTAN_USE_STD_TR1)
   #include <tr1/memory>
 #elif defined(BOTAN_USE_BOOST_TR1)
   #include <boost/tr1/memory.hpp>
@@ -17,6 +19,14 @@
 #endif
 
 namespace Botan {
+#ifndef BOTAN_SHARED_PTR
+#define BOTAN_SHARED_PTR
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+      using std::shared_ptr;
+#else
+      using std::tr1::shared_ptr;
+#endif
+#endif
 
 /**
 * This class is intended as an function call parameter type and
@@ -30,7 +40,7 @@ template<typename T>
 class BOTAN_DLL SharedPtrConverter
    {
    public:
-      typedef std::tr1::shared_ptr<T> SharedPtr;
+      typedef shared_ptr<T> SharedPtr;
 
       /**
       * Construct a null pointer equivalent object.
