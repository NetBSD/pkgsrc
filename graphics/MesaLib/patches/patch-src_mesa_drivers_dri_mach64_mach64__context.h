$NetBSD: patch-src_mesa_drivers_dri_mach64_mach64__context.h,v 1.1 2013/05/16 05:22:02 richard Exp $

--- src/mesa/drivers/dri/mach64/mach64_context.h.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/drivers/dri/mach64/mach64_context.h
@@ -37,7 +37,7 @@
 #include "mach64_drm.h"
 
 #include "main/mtypes.h"
-
+#include "main/macros.h"
 #include "mach64_reg.h"
 
 #include "texmem.h"
