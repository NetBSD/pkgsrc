$NetBSD: patch-stellarsolver_astrometry_util_qsort__reentrant.c,v 1.1 2026/05/03 06:38:33 wiz Exp $

https://github.com/rlancaste/stellarsolver/issues/150

--- stellarsolver/astrometry/util/qsort_reentrant.c.orig	2025-05-25 04:36:42.000000000 +0000
+++ stellarsolver/astrometry/util/qsort_reentrant.c
@@ -34,14 +34,14 @@
 # include <sys/cdefs.h>
 #endif
 //__FBSDID("$FreeBSD: src/sys/libkern/qsort.c,v 1.15 2004/07/15 23:58:23 glebius Exp $");
+#include "astrometry/os-features.h"
 
-
 // Astrometry.net: we lightly modified this file:
 // - renamed qsort_r to QSORT_R to avoid clashes with system version
 // - removed the preprocessor magic that support re-entrant and non-
 //   functions in the same source code.
 
-typedef int             cmp_t(void *, const void *, const void *);
+typedef int             QSORT_COMPARISON_FUNCTION(cmp_t, void *, const void *, const void *);
 
 static __inline char    *med3(char *, char *, char *, cmp_t *, void *);
 static __inline void     swapfunc(char *, char *, int, int);
