$NetBSD: patch-i18n_digitlst.cpp,v 1.4 2017/10/06 05:42:01 adam Exp $

Do not include xlocale.h, except for Darwin - not portable header,
also removed in current glibc.

--- i18n/digitlst.cpp.orig	2017-01-20 00:20:31.000000000 +0000
+++ i18n/digitlst.cpp
@@ -61,10 +61,10 @@
 #endif
 
 #if U_USE_STRTOD_L
-# if U_PLATFORM_USES_ONLY_WIN32_API || U_PLATFORM == U_PF_CYGWIN
-#   include <locale.h>
-# else
+# ifdef __APPLE__
 #   include <xlocale.h>
+# else
+#   include <locale.h>
 # endif
 #endif
 
