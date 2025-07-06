$NetBSD: patch-pillow__heif___pillow__heif.c,v 1.2 2025/07/06 19:01:44 wiz Exp $

Add header needed by libheif 1.20.1.
https://github.com/bigcat88/pillow_heif/issues/360

--- pillow_heif/_pillow_heif.c.orig	2025-07-06 18:59:30.893276993 +0000
+++ pillow_heif/_pillow_heif.c
@@ -2,6 +2,7 @@
 
 #include "Python.h"
 #include "libheif/heif.h"
+#include "libheif/heif_properties.h"
 #include "_ph_postprocess.h"
 
 /* =========== Common stuff ======== */
