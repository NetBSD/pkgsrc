$NetBSD: patch-src_lib_OpenEXRCore_internal__ht__quality.h,v 1.1 2026/09/28 14:39:29 wiz Exp $

Fix build on NetBSD.
https://github.com/AcademySoftwareFoundation/openexr/issues/2681

--- src/lib/OpenEXRCore/internal_ht_quality.h.orig	2026-09-28 14:35:15.632016677 +0000
+++ src/lib/OpenEXRCore/internal_ht_quality.h
@@ -6,7 +6,13 @@
 #ifndef OPENEXR_PRIVATE_HT_QUALITY_H
 #define OPENEXR_PRIVATE_HT_QUALITY_H
 
+#ifdef __cplusplus
+#include <cmath>
+#define _OPENEXR_ISFINITE	std::isfinite
+#else
 #include <math.h>
+#define _OPENEXR_ISFINITE	isfinite
+#endif
 
 /** Lower bound of the valid range for the LJ2K lossy quality level. */
 #define MIN_LOSSY_HTJ2K_QUALITY 1.f
@@ -17,7 +23,7 @@ is_lossy_htj2k_quality (float q)
 static inline int
 is_lossy_htj2k_quality (float q)
 {
-    return isfinite (q) && q >= MIN_LOSSY_HTJ2K_QUALITY &&
+    return _OPENEXR_ISFINITE (q) && q >= MIN_LOSSY_HTJ2K_QUALITY &&
            q <= MAX_LOSSY_HTJ2K_QUALITY;
 }
 
