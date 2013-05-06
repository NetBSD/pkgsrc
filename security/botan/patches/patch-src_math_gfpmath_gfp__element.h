$NetBSD: patch-src_math_gfpmath_gfp__element.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/math/gfpmath/gfp_element.h.orig	2013-04-30 22:49:33.000000000 +0000
+++ src/math/gfpmath/gfp_element.h
@@ -14,9 +14,12 @@
 
 #include <botan/bigint.h>
 #include <botan/gfp_modulus.h>
+#include <ciso646>
 #include <iosfwd>
 
-#if defined(BOTAN_USE_STD_TR1)
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  #include <memory>
+#elif defined(BOTAN_USE_STD_TR1)
   #include <tr1/memory>
 #elif defined(BOTAN_USE_BOOST_TR1)
   #include <boost/tr1/memory.hpp>
@@ -25,6 +28,14 @@
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
 
 struct Illegal_Transformation : public Exception
    {
@@ -40,7 +51,7 @@ struct Illegal_Transformation : public E
 class BOTAN_DLL GFpElement
    {
    private:
-      std::tr1::shared_ptr<GFpModulus> mp_mod;
+      shared_ptr<GFpModulus> mp_mod;
       mutable BigInt m_value; // ordinary residue or m-residue respectively
       mutable BigInt workspace;
 
@@ -79,7 +90,7 @@ class BOTAN_DLL GFpElement
       * @param value the element value
       * @param use_montgm whether this object will use Montgomery multiplication
       */
-      explicit GFpElement(std::tr1::shared_ptr<GFpModulus> const mod,
+      explicit GFpElement(shared_ptr<GFpModulus> const mod,
                           const BigInt& value, bool use_mongm = false);
 
       /**
@@ -190,7 +201,7 @@ class BOTAN_DLL GFpElement
       * the shared GFpModulus objects!
       * @result the shared pointer to the GFpModulus of *this
       */
-      inline std::tr1::shared_ptr<GFpModulus> const get_ptr_mod() const
+      inline shared_ptr<GFpModulus> const get_ptr_mod() const
          {
          return mp_mod;
          }
@@ -203,7 +214,7 @@ class BOTAN_DLL GFpElement
       * the shared GFpModulus objects!
       * @param mod a shared pointer to a GFpModulus that will be held in *this
       */
-      void set_shrd_mod(std::tr1::shared_ptr<GFpModulus> const mod);
+      void set_shrd_mod(shared_ptr<GFpModulus> const mod);
 
       /**
       * Tells whether this GFpElement is currently transformed to it´ m-residue,
