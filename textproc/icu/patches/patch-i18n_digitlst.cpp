$NetBSD: patch-i18n_digitlst.cpp,v 1.2 2016/12/12 17:46:39 adam Exp $

--- i18n/digitlst.cpp.orig	2016-10-27 01:37:56.000000000 +0000
+++ i18n/digitlst.cpp
@@ -61,7 +61,7 @@
 #endif
 
 #if U_USE_STRTOD_L
-# if U_PLATFORM_USES_ONLY_WIN32_API || U_PLATFORM == U_PF_CYGWIN
+# if U_PLATFORM_USES_ONLY_WIN32_API || U_PLATFORM == U_PF_CYGWIN || defined(__NetBSD__)
 #   include <locale.h>
 # else
 #   include <xlocale.h>
