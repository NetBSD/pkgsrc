$NetBSD: patch-content_svg_content_src_nsSVGFilters.h,v 1.1 2014/05/15 21:16:16 joerg Exp $

--- content/svg/content/src/nsSVGFilters.h.orig	2014-05-14 13:04:50.000000000 +0000
+++ content/svg/content/src/nsSVGFilters.h
@@ -237,4 +237,6 @@ protected:
   static LengthInfo sLengthInfo[4];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 #endif
