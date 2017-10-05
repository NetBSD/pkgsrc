$NetBSD: patch-i18n_digitlst.cpp,v 1.3 2017/10/05 22:50:30 maya Exp $

Never include xlocale.h - not portable header, also removed in current
glibc.

--- i18n/digitlst.cpp.orig	2017-01-20 00:20:31.000000000 +0000
+++ i18n/digitlst.cpp
@@ -61,11 +61,7 @@
 #endif
 
 #if U_USE_STRTOD_L
-# if U_PLATFORM_USES_ONLY_WIN32_API || U_PLATFORM == U_PF_CYGWIN
-#   include <locale.h>
-# else
-#   include <xlocale.h>
-# endif
+# include <locale.h>
 #endif
 
 // ***************************************************************************
