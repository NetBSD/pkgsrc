$NetBSD: patch-src_common_mathmisc.h,v 1.1 2026/03/27 09:37:22 pin Exp $

Include missing header.

--- src/common/mathmisc.h.orig	2026-03-27 09:16:01.189290496 +0000
+++ src/common/mathmisc.h
@@ -25,6 +25,7 @@
 #define RUBBERBAND_MATHMISC_H
 
 #include "sysutils.h"
+#include "cstddef"
 
 #ifndef M_PI
 #define M_PI 3.14159265358979323846
