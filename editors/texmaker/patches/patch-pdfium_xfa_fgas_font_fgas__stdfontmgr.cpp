$NetBSD: patch-pdfium_xfa_fgas_font_fgas__stdfontmgr.cpp,v 1.1 2019/09/05 08:07:25 nros Exp $
* add X11 and pkgsrc font paths
--- pdfium/xfa/fgas/font/fgas_stdfontmgr.cpp.orig	2017-04-16 14:53:52.000000000 +0000
+++ pdfium/xfa/fgas/font/fgas_stdfontmgr.cpp
@@ -466,8 +466,12 @@ const FX_CHAR* g_FontFolders[] = {
 #if _FXM_PLATFORM_ == _FXM_PLATFORM_LINUX_
     "/usr/share/fonts", "/usr/share/X11/fonts/Type1",
     "/usr/share/X11/fonts/TTF", "/usr/local/share/fonts",
+    "/usr/X11R7/lib/X11/fonts/Type1", "/usr/X11R7/lib/X11/fonts/TTF",
+    "/usr/X11R6/lib/X11/fonts/Type1", "/usr/X11R6/lib/X11/fonts/TTF",
+#include "fgas_stdfontmgr_pkgsrcfonts.inc"
 #elif _FXM_PLATFORM_ == _FXM_PLATFORM_APPLE_
     "~/Library/Fonts", "/Library/Fonts", "/System/Library/Fonts",
+#include "fgas_stdfontmgr_pkgsrcfonts.inc"
 #elif _FXM_PLATFORM_ == _FXM_PLATFORM_ANDROID_
     "/system/fonts",
 #endif
