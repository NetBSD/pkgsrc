$NetBSD: patch-src_math_gfpmath_point__gfp.h,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/math/gfpmath/point_gfp.h.orig	2013-04-30 22:54:19.000000000 +0000
+++ src/math/gfpmath/point_gfp.h
@@ -234,7 +234,7 @@ class BOTAN_DLL PointGFp
       * @param mod a shared pointer to a GFpModulus that will
       * be held in the members *this
       */
-      void set_shrd_mod(std::tr1::shared_ptr<GFpModulus> p_mod);
+      void set_shrd_mod(shared_ptr<GFpModulus> p_mod);
 
       static GFpElement decompress(bool yMod2, GFpElement const& x, const CurveGFp& curve);
 
@@ -242,9 +242,9 @@ class BOTAN_DLL PointGFp
       static const u32bit GFPEL_WKSP_SIZE = 9;
       void ensure_worksp() const;
 
-      inline std::tr1::shared_ptr<PointGFp> mult_loop(int l, const BigInt& m,
-                                                      std::tr1::shared_ptr<PointGFp> H,
-                                                      std::tr1::shared_ptr<PointGFp> tmp,
+      inline shared_ptr<PointGFp> mult_loop(int l, const BigInt& m,
+                                                      shared_ptr<PointGFp> H,
+                                                      shared_ptr<PointGFp> tmp,
                                                       const PointGFp& P);
 
       CurveGFp mC;
@@ -257,7 +257,7 @@ class BOTAN_DLL PointGFp
       mutable bool mZpow2_set;
       mutable bool mZpow3_set;
       mutable bool mAZpow4_set;
-      mutable std::tr1::shared_ptr<std::vector<GFpElement> > mp_worksp_gfp_el;
+      mutable shared_ptr<std::vector<GFpElement> > mp_worksp_gfp_el;
 
    };
 
