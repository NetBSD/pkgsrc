$NetBSD: patch-libstdc++-v3_config_os_bsd_openbsd_os__defines.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- libstdc++-v3/config/os/bsd/openbsd/os_defines.h.orig	2013-02-03 17:54:05.000000000 +0000
+++ libstdc++-v3/config/os/bsd/openbsd/os_defines.h
@@ -38,4 +38,6 @@
 #define _GLIBCXX_USE_C99_FLOAT_TRANSCENDENTALS_DYNAMIC _GLIBCXX_USE_C99_DYNAMIC
 #define _GLIBCXX_USE_C99_FP_MACROS_DYNAMIC _GLIBCXX_USE_C99_DYNAMIC
 
+#undef _GLIBCXX_HAVE_GETS
+
 #endif
