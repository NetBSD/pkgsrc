$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.h,v 1.1 2014/05/18 21:28:28 joerg Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.h.orig	2013-01-05 14:21:58.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.h
@@ -237,4 +237,6 @@ protected:
   static LengthInfo sLengthInfo[4];
 };
 
+NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+
 #endif
