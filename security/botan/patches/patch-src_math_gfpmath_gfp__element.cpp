$NetBSD: patch-src_math_gfpmath_gfp__element.cpp,v 1.1 2013/05/06 14:58:20 joerg Exp $

--- src/math/gfpmath/gfp_element.cpp.orig	2013-04-30 23:08:30.000000000 +0000
+++ src/math/gfpmath/gfp_element.cpp
@@ -174,13 +174,13 @@ GFpElement::GFpElement(const BigInt& p, 
      m_is_trf(false)
    {
    assert(mp_mod.get() == 0);
-   mp_mod = std::tr1::shared_ptr<GFpModulus>(new GFpModulus(p));
+   mp_mod = shared_ptr<GFpModulus>(new GFpModulus(p));
    assert(mp_mod->m_p_dash == 0);
    if(m_use_montgm)
       ensure_montgm_precomp();
    }
 
-GFpElement::GFpElement(std::tr1::shared_ptr<GFpModulus> const mod, const BigInt& value, bool use_montgm)
+GFpElement::GFpElement(shared_ptr<GFpModulus> const mod, const BigInt& value, bool use_montgm)
    : mp_mod(),
      m_value(value % mod->m_p),
      m_use_montgm(use_montgm),
@@ -247,7 +247,7 @@ void GFpElement::ensure_montgm_precomp()
 
    }
 
-void GFpElement::set_shrd_mod(std::tr1::shared_ptr<GFpModulus> const p_mod)
+void GFpElement::set_shrd_mod(shared_ptr<GFpModulus> const p_mod)
    {
    mp_mod = p_mod;
    }
