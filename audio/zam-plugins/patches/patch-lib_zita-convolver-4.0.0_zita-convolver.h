$NetBSD: patch-lib_zita-convolver-4.0.0_zita-convolver.h,v 1.1 2022/04/06 16:32:21 nia Exp $

Use POSIX code path on all non-Apple systems (there is
a separate code path for macOS).

--- lib/zita-convolver-4.0.0/zita-convolver.h.orig	2020-12-20 06:54:49.000000000 +0000
+++ lib/zita-convolver-4.0.0/zita-convolver.h
@@ -45,7 +45,7 @@ extern int zita_convolver_minor_version 
 //XXX DZ: Hack for windows/osx10.5
 #include "zcsema-osx-win-compat.h"
 
-#if defined(__linux__)  || defined(__GNU__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__unix__) && !defined(__APPLE__)
 
 #include <semaphore.h>
 
