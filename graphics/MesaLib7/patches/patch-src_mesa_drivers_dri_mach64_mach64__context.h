$NetBSD: patch-src_mesa_drivers_dri_mach64_mach64__context.h,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/mach64/mach64_context.h.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/drivers/dri/mach64/mach64_context.h
@@ -37,7 +37,7 @@
 #include "mach64_drm.h"
 
 #include "main/mtypes.h"
-
+#include "main/macros.h"
 #include "mach64_reg.h"
 
 #include "texmem.h"
@@ -298,6 +298,9 @@ extern GLboolean mach64UnbindContext( __
 #if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #define bswap_32 bswap32
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/endian.h>
+#define bswap_32 bswap32
 #else
 #include <byteswap.h>
 #endif
