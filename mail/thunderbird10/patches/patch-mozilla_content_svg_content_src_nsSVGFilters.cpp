$NetBSD: patch-mozilla_content_svg_content_src_nsSVGFilters.cpp,v 1.1 2014/05/18 21:28:28 joerg Exp $

--- mozilla/content/svg/content/src/nsSVGFilters.cpp.orig	2013-01-05 14:21:58.000000000 +0000
+++ mozilla/content/svg/content/src/nsSVGFilters.cpp
@@ -119,7 +119,7 @@ nsSVGElement::LengthInfo nsSVGFE::sLengt
 NS_IMPL_ADDREF_INHERITED(nsSVGFE,nsSVGFEBase)
 NS_IMPL_RELEASE_INHERITED(nsSVGFE,nsSVGFEBase)
 
-NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
+//NS_DEFINE_STATIC_IID_ACCESSOR(nsSVGFE, NS_SVG_FE_CID)
 
 NS_INTERFACE_MAP_BEGIN(nsSVGFE)
    // nsISupports is an ambiguous base of nsSVGFE so we have to work
