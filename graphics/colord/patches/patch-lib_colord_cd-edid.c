$NetBSD: patch-lib_colord_cd-edid.c,v 1.1 2026/04/26 14:48:56 vins Exp $

Make udev support optional.

--- lib/colord/cd-edid.c.orig	2025-06-23 14:06:37.000000000 +0000
+++ lib/colord/cd-edid.c
@@ -25,7 +25,9 @@
 #include <string.h>
 #include <glib-object.h>
 #include <math.h>
+#ifdef HAVE_LIBUDEV
 #include <libudev.h>
+#endif
 
 #include "cd-edid.h"
 #include "cd-quirk.h"
