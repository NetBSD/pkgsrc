$NetBSD: patch-src_plugins.h,v 1.1 2018/11/14 15:25:28 hauke Exp $

using libtool 2.x
http://sources.gentoo.org/cgi-bin/viewvc.cgi/gentoo-x86/net-misc/siproxd/files/siproxd-libtool-2.4.patch?view=markup

--- src/plugins.h.orig	2015-10-15 15:29:20.000000000 +0200
+++ src/plugins.h	2017-04-03 22:25:39.000000000 +0200
@@ -41,6 +41,12 @@
 
 /* Plugins must return STS_SUCCESS / SUCCESS_FAILURE */
 
+#ifndef lt__PROGRAM__LTX_preloaded_symbols
+#define lt__PROGRAM__LTX_preloaded_symbols lt_libltdl_LTX_preloaded_symbols
+#endif
+#ifndef lt_libltdl_LTX_preloaded_symbols
+extern LT_DLSYM_CONST lt_dlsymlist lt__PROGRAM__LTX_preloaded_symbols[];
+#endif
 
 /*
  * Processing stages for Plugins
