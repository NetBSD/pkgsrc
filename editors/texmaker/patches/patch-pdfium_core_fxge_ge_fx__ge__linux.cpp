$NetBSD: patch-pdfium_core_fxge_ge_fx__ge__linux.cpp,v 1.3 2021/10/26 17:56:54 nros Exp $

* Add X11 and pkgsrc font paths

--- pdfium/core/fxge/ge/fx_ge_linux.cpp.orig	2017-04-16 14:53:52.000000000 +0000
+++ pdfium/core/fxge/ge/fx_ge_linux.cpp
@@ -1,3 +1,4 @@
+
 // Copyright 2014 PDFium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
@@ -132,6 +133,8 @@ std::unique_ptr<IFX_SystemFontInfo> IFX_
     pInfo->AddPath("/usr/share/X11/fonts/Type1");
     pInfo->AddPath("/usr/share/X11/fonts/TTF");
     pInfo->AddPath("/usr/local/share/fonts");
+#include "../fxge_x11fonts.inc"
+#include "../fxge_pkgsrcfonts.inc"
   }
   return std::unique_ptr<IFX_SystemFontInfo>(pInfo);
 }
