$NetBSD: patch-content_svg_content_src_nsSVGFilters.h,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- content/svg/content/src/nsSVGFilters.h.orig	2013-11-13 23:35:10.000000000 +0000
+++ content/svg/content/src/nsSVGFilters.h
@@ -212,6 +212,8 @@ protected:
   static LengthInfo sLengthInfo[4];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 typedef nsSVGFE nsSVGFEImageElementBase;
 
 class nsSVGFEImageElement : public nsSVGFEImageElementBase,
