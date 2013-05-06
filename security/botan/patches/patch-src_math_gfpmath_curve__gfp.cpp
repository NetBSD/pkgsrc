$NetBSD: patch-src_math_gfpmath_curve__gfp.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/math/gfpmath/curve_gfp.cpp.orig	2013-04-30 23:08:27.000000000 +0000
+++ src/math/gfpmath/curve_gfp.cpp
@@ -14,7 +14,7 @@
 
 namespace Botan {
 
-void CurveGFp::set_shrd_mod(const std::tr1::shared_ptr<GFpModulus> mod)
+void CurveGFp::set_shrd_mod(const shared_ptr<GFpModulus> mod)
    {
    mp_mod = mod;
    mA.turn_off_sp_red_mul();// m.m. is not needed, must be trf. back
@@ -34,7 +34,7 @@ CurveGFp::CurveGFp(const GFpElement& a, 
       {
       throw Invalid_Argument("could not construct curve: moduli of arguments differ");
       }
-   std::tr1::shared_ptr<GFpModulus> p_mod = std::tr1::shared_ptr<GFpModulus>(new GFpModulus(p));
+   shared_ptr<GFpModulus> p_mod = shared_ptr<GFpModulus>(new GFpModulus(p));
    // the above is the creation of the GFpModuls object which will be shared point-wide
    // (in the context of a point of course)
    set_shrd_mod(p_mod);
@@ -44,21 +44,21 @@ CurveGFp::CurveGFp(const CurveGFp& other
    :	mA(other.get_a()),
         mB(other.get_b())
    {
-   mp_mod = std::tr1::shared_ptr<GFpModulus>(new GFpModulus(*other.mp_mod));
+   mp_mod = shared_ptr<GFpModulus>(new GFpModulus(*other.mp_mod));
    assert(mp_mod->p_equal_to(mA.get_p()));
    assert(mp_mod->p_equal_to(mB.get_p()));
    set_shrd_mod(mp_mod);
    if(other.mp_mres_a.get())
       {
-      mp_mres_a = std::tr1::shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_a));
+      mp_mres_a = shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_a));
       }
    if(other.mp_mres_b.get())
       {
-      mp_mres_b = std::tr1::shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_b));
+      mp_mres_b = shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_b));
       }
    if(other.mp_mres_one.get())
       {
-      mp_mres_one = std::tr1::shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_one));
+      mp_mres_one = shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_one));
       }
 
    }
@@ -72,21 +72,21 @@ const CurveGFp& CurveGFp::operator=(cons
    mA.swap(a_tmp);
    mB.swap(b_tmp);
 
-   std::tr1::shared_ptr<GFpModulus> p_mod = std::tr1::shared_ptr<GFpModulus>(new GFpModulus(*other.mp_mod));
+   shared_ptr<GFpModulus> p_mod = shared_ptr<GFpModulus>(new GFpModulus(*other.mp_mod));
    set_shrd_mod(p_mod);
 
    // exception safety note: no problem if we have a throw from here on...
    if(other.mp_mres_a.get())
       {
-      mp_mres_a = std::tr1::shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_a));
+      mp_mres_a = shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_a));
       }
    if(other.mp_mres_b.get())
       {
-      mp_mres_b = std::tr1::shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_b));
+      mp_mres_b = shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_b));
       }
    if(other.mp_mres_one.get())
       {
-      mp_mres_one = std::tr1::shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_one));
+      mp_mres_one = shared_ptr<GFpElement>(new GFpElement(*other.mp_mres_one));
       }
    return *this;
    }
@@ -123,7 +123,7 @@ GFpElement const CurveGFp::get_mres_a() 
    {
    if(mp_mres_a.get() == 0)
       {
-      mp_mres_a = std::tr1::shared_ptr<GFpElement>(new GFpElement(mA));
+      mp_mres_a = shared_ptr<GFpElement>(new GFpElement(mA));
       mp_mres_a->turn_on_sp_red_mul();
       mp_mres_a->get_mres();
       }
@@ -134,18 +134,18 @@ GFpElement const CurveGFp::get_mres_b() 
    {
    if(mp_mres_b.get() == 0)
       {
-      mp_mres_b = std::tr1::shared_ptr<GFpElement>(new GFpElement(mB));
+      mp_mres_b = shared_ptr<GFpElement>(new GFpElement(mB));
       mp_mres_b->turn_on_sp_red_mul();
       mp_mres_b->get_mres();
       }
    return GFpElement(*mp_mres_b);
    }
 
-std::tr1::shared_ptr<GFpElement const> const CurveGFp::get_mres_one() const
+shared_ptr<GFpElement const> const CurveGFp::get_mres_one() const
    {
    if(mp_mres_one.get() == 0)
       {
-      mp_mres_one = std::tr1::shared_ptr<GFpElement>(new GFpElement(mp_mod->get_p(), 1));
+      mp_mres_one = shared_ptr<GFpElement>(new GFpElement(mp_mod->get_p(), 1));
       mp_mres_one->turn_on_sp_red_mul();
       mp_mres_one->get_mres();
       }
