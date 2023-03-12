$NetBSD: patch-core_dplugins_generic_tools_mediaserver_upnpsdk_Neptune_Source_Core_NptConfig.h,v 1.1 2023/03/12 14:36:29 wiz Exp $

Add NetBSD support.

--- core/dplugins/generic/tools/mediaserver/upnpsdk/Neptune/Source/Core/NptConfig.h.orig	2022-12-03 13:19:38.000000000 +0000
+++ core/dplugins/generic/tools/mediaserver/upnpsdk/Neptune/Source/Core/NptConfig.h
@@ -136,6 +136,11 @@
 #define NPT_CONFIG_HAVE_GETADDRINFO
 #endif
 
+/* NetBSD */
+#if defined(__NetBSD__)
+#define NPT_CONFIG_HAVE_GETADDRINFO
+#endif
+
 /* linux */
 #if defined(__linux__)
 #define NPT_CONFIG_HAVE_GETADDRINFO
