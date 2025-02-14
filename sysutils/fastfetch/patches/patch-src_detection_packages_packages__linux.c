$NetBSD: patch-src_detection_packages_packages__linux.c,v 1.1 2025/02/14 13:26:54 vins Exp $

Enable pkgsrc support on Linux.

--- src/detection/packages/packages_linux.c.orig	2025-02-11 02:40:51.000000000 +0000
+++ src/detection/packages/packages_linux.c
@@ -680,4 +680,7 @@ void ffDetectPackagesImpl(FFPackagesResu
 
     if (!(options->disabled & FF_PACKAGES_FLAG_AM_BIT))
         result->amUser = getAMUser();
+
+    if (!(options->disabled & FF_PACKAGES_FLAG_PKGSRC_BIT))
+        result->pkgsrc = ffPackagesGetNumElements(FASTFETCH_TARGET_DIR_ROOT "/usr/pkg/pkgdb", DT_DIR);
 }
