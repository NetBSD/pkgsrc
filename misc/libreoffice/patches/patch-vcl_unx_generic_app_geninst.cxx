$NetBSD: patch-vcl_unx_generic_app_geninst.cxx,v 1.5 2026/09/22 08:34:00 ryoon Exp $

Set "OS Environment" on NetBSD,same as FreeBSD.

To Fix:
Help -> About LibreOffice
 Environment: OS: unknown

Tweaked by Yasushi Oshima, PR pkg/56048.

--- vcl/unx/generic/app/geninst.cxx.orig	2026-08-21 12:51:44.000000000 +0000
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,7 +22,7 @@
 #if defined(LINUX)
 #  include <stdio.h>
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/utsname.h>
 #endif
 #if defined(__EMSCRIPTEN__)
