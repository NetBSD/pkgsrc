$NetBSD: patch-pdfium_core_fxge_apple_fx__mac__imp.cpp,v 1.2 2021/10/26 17:56:54 nros Exp $

* add pkgsrc font paths

--- pdfium/core/fxge/apple/fx_mac_imp.cpp.orig	2017-04-16 14:53:52.000000000 +0000
+++ pdfium/core/fxge/apple/fx_mac_imp.cpp
@@ -123,6 +123,7 @@ std::unique_ptr<IFX_SystemFontInfo> IFX_
   pInfo->AddPath("~/Library/Fonts");
   pInfo->AddPath("/Library/Fonts");
   pInfo->AddPath("/System/Library/Fonts");
+#include "../fxge_pkgsrcfonts.inc"
   return std::unique_ptr<CFX_MacFontInfo>(pInfo);
 }
 
