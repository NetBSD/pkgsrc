$NetBSD: patch-i18n_digitlst.cpp,v 1.5 2017/10/06 15:20:42 maya Exp $

Avoid including xlocale.h on linux and netbsd, which don't have
xlocale.h

--- i18n/digitlst.cpp.orig	2017-01-20 00:20:31.000000000 +0000
+++ i18n/digitlst.cpp
@@ -61,10 +61,10 @@
 #endif
 
 #if U_USE_STRTOD_L
-# if U_PLATFORM_USES_ONLY_WIN32_API || U_PLATFORM == U_PF_CYGWIN
-#   include <locale.h>
-# else
+# if !defined(__NetBSD__) && !defined(__linux__)
 #   include <xlocale.h>
+# else
+#   include <locale.h>
 # endif
 #endif
 
