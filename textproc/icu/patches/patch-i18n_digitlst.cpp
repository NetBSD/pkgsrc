$NetBSD: patch-i18n_digitlst.cpp,v 1.1 2016/12/04 04:11:33 ryoon Exp $

--- i18n/digitlst.cpp.orig	2016-10-17 05:10:38.000000000 +0000
+++ i18n/digitlst.cpp
@@ -61,7 +61,7 @@
 #endif
 
 #if U_USE_STRTOD_L && !U_PLATFORM_USES_ONLY_WIN32_API
-# if U_PLATFORM == U_PF_CYGWIN
+# if (U_PLATFORM == U_PF_CYGWIN) || defined(__NetBSD__)
 #   include <locale.h>
 # else
 #   include <xlocale.h>
