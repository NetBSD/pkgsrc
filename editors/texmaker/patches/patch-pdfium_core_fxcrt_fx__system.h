$NetBSD: patch-pdfium_core_fxcrt_fx__system.h,v 1.1 2021/10/26 17:56:54 nros Exp $

* build in BSD and solaris

--- pdfium/core/fxcrt/fx_system.h.orig	2019-12-05 18:23:22.000000000 +0000
+++ pdfium/core/fxcrt/fx_system.h
@@ -40,7 +40,7 @@
 #elif defined(_WIN64)
 #define _FX_OS_ _FX_WIN64_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__sun)
 #define _FX_OS_ _FX_LINUX_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_LINUX_
 #elif defined(__APPLE__)
