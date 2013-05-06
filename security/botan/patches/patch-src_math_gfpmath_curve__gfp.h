$NetBSD: patch-src_math_gfpmath_curve__gfp.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/math/gfpmath/curve_gfp.h.orig	2013-04-30 22:53:40.000000000 +0000
+++ src/math/gfpmath/curve_gfp.h
@@ -57,7 +57,7 @@ class BOTAN_DLL CurveGFp
       * @param mod a shared pointer to a GFpModulus object suitable for
       * *this.
       */
-      void set_shrd_mod(const std::tr1::shared_ptr<GFpModulus> mod);
+      void set_shrd_mod(const shared_ptr<GFpModulus> mod);
 
       // getters
 
@@ -99,14 +99,14 @@ class BOTAN_DLL CurveGFp
       * function.
       * @result the GFpElement 1, transformed to its m-residue
       */
-      std::tr1::shared_ptr<GFpElement const> const get_mres_one() const;
+      shared_ptr<GFpElement const> const get_mres_one() const;
 
       /**
       * Get prime modulus of the field of the curve
       * @result prime modulus of the field of the curve
       */
       BigInt const get_p() const;
-      /*inline std::tr1::shared_ptr<BigInt> const get_ptr_p() const
+      /*inline shared_ptr<BigInt> const get_ptr_p() const
       {
       return mp_p;
       }*/
@@ -119,7 +119,7 @@ class BOTAN_DLL CurveGFp
       * Do NOT spread pointers to a GFpModulus over different threads!
       * @result a shared pointer to a GFpModulus object
       */
-      inline std::tr1::shared_ptr<GFpModulus> const get_ptr_mod() const
+      inline shared_ptr<GFpModulus> const get_ptr_mod() const
          {
          return mp_mod;
          }
@@ -131,12 +131,12 @@ class BOTAN_DLL CurveGFp
       void swap(CurveGFp& other);
 
    private:
-      std::tr1::shared_ptr<GFpModulus> mp_mod;
+      shared_ptr<GFpModulus> mp_mod;
       GFpElement mA;
       GFpElement mB;
-      mutable std::tr1::shared_ptr<GFpElement> mp_mres_a;
-      mutable std::tr1::shared_ptr<GFpElement> mp_mres_b;
-      mutable std::tr1::shared_ptr<GFpElement> mp_mres_one;
+      mutable shared_ptr<GFpElement> mp_mres_a;
+      mutable shared_ptr<GFpElement> mp_mres_b;
+      mutable shared_ptr<GFpElement> mp_mres_one;
    };
 
 // relational operators
