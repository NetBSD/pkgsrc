$NetBSD: patch-toolkit_toolkit-tiers.mk,v 1.1.1.1 2012/03/15 09:45:29 ryoon Exp $

--- mozilla/toolkit/toolkit-tiers.mk.orig	2012-02-16 10:25:31.000000000 +0000
+++ mozilla/toolkit/toolkit-tiers.mk
@@ -82,7 +82,7 @@ ifndef MOZ_NATIVE_BZ2
 tier_platform_dirs += modules/libbz2
 endif
 tier_platform_dirs += modules/libmar
-tier_platform_dirs += other-licenses/bsdiff
+#tier_platform_dirs += other-licenses/bsdiff
 endif
 
 tier_platform_dirs	+= gfx/qcms
