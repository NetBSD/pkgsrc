$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.h,v 1.1 2014/05/27 09:58:51 joerg Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.h.orig	2013-11-18 16:29:53.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.h
@@ -303,6 +303,8 @@ protected:
   SVGAnimatedPreserveAspectRatio mPreserveAspectRatio;
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 typedef nsSVGElement SVGFEUnstyledElementBase;
 
 class SVGFEUnstyledElement : public SVGFEUnstyledElementBase
