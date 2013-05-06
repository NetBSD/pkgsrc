$NetBSD: patch-src_math_gfpmath_point__gfp.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/math/gfpmath/point_gfp.cpp.orig	2013-04-30 23:08:32.000000000 +0000
+++ src/math/gfpmath/point_gfp.cpp
@@ -109,7 +109,7 @@ const PointGFp& PointGFp::assign_within_
    return *this;
    }
 
-void PointGFp::set_shrd_mod(std::tr1::shared_ptr<GFpModulus> p_mod)
+void PointGFp::set_shrd_mod(shared_ptr<GFpModulus> p_mod)
    {
    mX.set_shrd_mod(p_mod);
    mY.set_shrd_mod(p_mod);
@@ -133,7 +133,7 @@ void PointGFp::ensure_worksp() const
          }
       }
 
-   mp_worksp_gfp_el = std::tr1::shared_ptr<std::vector<GFpElement> >(new std::vector<GFpElement>);
+   mp_worksp_gfp_el = shared_ptr<std::vector<GFpElement> >(new std::vector<GFpElement>);
    mp_worksp_gfp_el->reserve(9);
    for (u32bit i=0; i<GFPEL_WKSP_SIZE; i++)
       {
@@ -337,8 +337,8 @@ PointGFp& PointGFp::mult_this_secure(con
    // use montgomery mult. in this operation
    this->turn_on_sp_red_mul();
 
-   std::tr1::shared_ptr<PointGFp> H(new PointGFp(this->mC));
-   std::tr1::shared_ptr<PointGFp> tmp; // used for AADA
+   shared_ptr<PointGFp> H(new PointGFp(this->mC));
+   shared_ptr<PointGFp> tmp; // used for AADA
 
    PointGFp P(*this);
    BigInt m(scalar);
@@ -477,15 +477,15 @@ PointGFp& PointGFp::operator*=(const Big
    return *this;
    }
 
-inline std::tr1::shared_ptr<PointGFp> PointGFp::mult_loop(int l,
+inline shared_ptr<PointGFp> PointGFp::mult_loop(int l,
                                                           const BigInt& m,
-                                                          std::tr1::shared_ptr<PointGFp> H,
-                                                          std::tr1::shared_ptr<PointGFp> tmp,
+                                                          shared_ptr<PointGFp> H,
+                                                          shared_ptr<PointGFp> tmp,
                                                           const PointGFp& P)
    {
    //assert(l >= (int)m.bits()- 1);
    tmp = H;
-   std::tr1::shared_ptr<PointGFp> to_add(new PointGFp(P)); // we just need some point
+   shared_ptr<PointGFp> to_add(new PointGFp(P)); // we just need some point
    // so that we can use op=
    // inside the loop
    for (int i=l; i >=0; i--)
