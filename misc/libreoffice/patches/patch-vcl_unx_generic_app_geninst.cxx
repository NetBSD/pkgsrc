$NetBSD: patch-vcl_unx_generic_app_geninst.cxx,v 1.4 2025/02/05 03:50:02 ryoon Exp $

Set "OS Environment" on NetBSD,same as FreeBSD.

To Fix:
Help -> About LibreOffice
 Environment: OS: unknown

Tweaked by Yasushi Oshima, PR pkg/56048.

--- vcl/unx/generic/app/geninst.cxx.orig	2025-01-30 14:20:37.576103520 +0000
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 #if defined(EMSCRIPTEN)
