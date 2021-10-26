$NetBSD: patch-pdfium_xfa_fgas_font_cfgas__fontmgr.cpp,v 1.1 2021/10/26 17:56:54 nros Exp $

* add X11 and pkgsrc font paths

--- pdfium/xfa/fgas/font/cfgas_fontmgr.cpp.orig	2021-10-25 14:58:20.286381904 +0000
+++ pdfium/xfa/fgas/font/cfgas_fontmgr.cpp
@@ -425,8 +425,11 @@ const FX_CHAR* g_FontFolders[] = {
 #if _FXM_PLATFORM_ == _FXM_PLATFORM_LINUX_
     "/usr/share/fonts", "/usr/share/X11/fonts/Type1",
     "/usr/share/X11/fonts/TTF", "/usr/local/share/fonts",
+#include "fgas_stdfontmgr_x11fonts.inc"
+#include "fgas_stdfontmgr_pkgsrcfonts.inc"
 #elif _FXM_PLATFORM_ == _FXM_PLATFORM_APPLE_
     "~/Library/Fonts", "/Library/Fonts", "/System/Library/Fonts",
+#include "fgas_stdfontmgr_pkgsrcfonts.inc"
 #elif _FXM_PLATFORM_ == _FXM_PLATFORM_ANDROID_
     "/system/fonts",
 #endif
