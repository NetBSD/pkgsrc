$NetBSD: patch-src_wxcurl_base.cpp,v 1.1 2019/03/25 11:57:29 bouyer Exp $

--- src/wxcurl/base.cpp.orig	2019-02-22 14:45:09.299106561 +0100
+++ src/wxcurl/base.cpp	2019-02-22 14:45:12.375254626 +0100
@@ -28,6 +28,7 @@
 
 #include <wx/curl/base.h>
 #include <wx/filename.h>
+#include <cmath> // for isnan
 
 
 //////////////////////////////////////////////////////////////////////
