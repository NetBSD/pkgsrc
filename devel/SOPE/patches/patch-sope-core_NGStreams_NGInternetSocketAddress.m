$NetBSD: patch-sope-core_NGStreams_NGInternetSocketAddress.m,v 1.1 2012/09/01 10:02:34 marino Exp $

--- sope-core/NGStreams/NGInternetSocketAddress.m.orig	2011-11-04 12:39:19.000000000 +0000
+++ sope-core/NGStreams/NGInternetSocketAddress.m
@@ -48,7 +48,7 @@
 #include "NGInternetSocketDomain.h"
 #include "common.h"
 
-#if defined(HAVE_GETHOSTBYNAME_R) && !defined(linux) && !defined(__FreeBSD__)
+#if defined(HAVE_GETHOSTBYNAME_R) && !defined(linux) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #define USE_GETHOSTBYNAME_R 1
 #endif
 
