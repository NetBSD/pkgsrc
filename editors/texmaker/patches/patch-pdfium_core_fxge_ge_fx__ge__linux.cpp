$NetBSD: patch-pdfium_core_fxge_ge_fx__ge__linux.cpp,v 1.1 2019/09/05 08:07:25 nros Exp $
* Add X11 and pkgsrc font paths
--- pdfium/core/fxge/ge/fx_ge_linux.cpp.orig	2017-04-16 14:53:52.000000000 +0000
+++ pdfium/core/fxge/ge/fx_ge_linux.cpp
@@ -1,3 +1,4 @@
+
 // Copyright 2014 PDFium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
@@ -132,6 +133,11 @@ std::unique_ptr<IFX_SystemFontInfo> IFX_
     pInfo->AddPath("/usr/share/X11/fonts/Type1");
     pInfo->AddPath("/usr/share/X11/fonts/TTF");
     pInfo->AddPath("/usr/local/share/fonts");
+    pInfo->AddPath("/usr/X11R7/lib/X11/fonts/Type1");
+    pInfo->AddPath("/usr/X11R7/lib/X11/fonts/TTF");
+    pInfo->AddPath("/usr/X11R6/lib/X11/fonts/Type1");
+    pInfo->AddPath("/usr/X11R6/lib/X11/fonts/TTF");
+#include "../fxge_pkgsrcfonts.inc"
   }
   return std::unique_ptr<IFX_SystemFontInfo>(pInfo);
 }
