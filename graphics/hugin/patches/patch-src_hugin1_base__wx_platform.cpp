$NetBSD: patch-src_hugin1_base__wx_platform.cpp,v 1.3 2025/11/19 16:00:48 adam Exp $

Needs definition of HuginMessageBox.

--- src/hugin1/base_wx/platform.cpp.orig	2025-11-19 06:43:12.570695369 +0000
+++ src/hugin1/base_wx/platform.cpp
@@ -28,6 +28,7 @@
 
 #include <hugin_utils/utils.h>
 #include <vigra/imageinfo.hxx>
+#include "base_wx/wxutils.h"
 
 /** build filter string "*.ext", adds also upper case version for UNIX paths when needed */
 wxString GetFilterExtensions(const wxString& ext)
