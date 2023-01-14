$NetBSD: patch-sope-core_NGStreams_NGInternetSocketAddress.m,v 1.4 2023/01/14 01:44:42 manu Exp $

NetBSD and DragonflyBSD do not have gethostaddr_r()

--- sope-core/NGStreams/NGInternetSocketAddress.m.orig	2023-01-12 16:36:29.711686829 +0100
+++ sope-core/NGStreams/NGInternetSocketAddress.m	2023-01-12 16:36:47.732046372 +0100
@@ -47,9 +47,9 @@
 #include "NGInternetSocketAddress.h"
 #include "NGInternetSocketDomain.h"
 #include "common.h"
 
-#if defined(HAVE_GETHOSTBYNAME_R) && !defined(linux) && !defined(__FreeBSD__) && !defined(__GLIBC__)
+#if defined(HAVE_GETHOSTBYNAME_R) && !defined(linux) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__GLIBC__) && !defined(__DragonFly__)
 #define USE_GETHOSTBYNAME_R 1
 #endif
 
 @implementation NGInternetSocketAddress
