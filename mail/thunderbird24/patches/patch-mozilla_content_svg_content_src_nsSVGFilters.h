$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.h,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.h.orig	2014-04-24 16:26:42.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.h
@@ -233,6 +233,8 @@ protected:
   static LengthInfo sLengthInfo[4];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 typedef nsSVGElement SVGFEUnstyledElementBase;
 
 class SVGFEUnstyledElement : public SVGFEUnstyledElementBase
