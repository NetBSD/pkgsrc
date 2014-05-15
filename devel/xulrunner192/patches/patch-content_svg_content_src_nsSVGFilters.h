$NetBSD: patch-content_svg_content_src_nsSVGFilters.h,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- content/svg/content/src/nsSVGFilters.h.orig	2012-03-06 14:45:24.000000000 +0000
+++ content/svg/content/src/nsSVGFilters.h
@@ -223,4 +223,6 @@ protected:
   static LengthInfo sLengthInfo[4];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 #endif
