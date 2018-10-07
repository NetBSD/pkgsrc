$NetBSD: patch-src_mesa_drivers_dri_i965_brw__performance__query.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Prevents libdrm i915_drm.h header from being used.
libdrm 2.4.88 does not have certain symbols defined in its i915_drm.h.

--- src/mesa/drivers/dri/i965/brw_performance_query.c.orig	2017-10-19 12:23:53.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_performance_query.c
@@ -56,7 +56,7 @@
 #include <sys/ioctl.h>
 
 #include <xf86drm.h>
-#include <i915_drm.h>
+#include "drm-uapi/i915_drm.h"
 
 #include "main/hash.h"
 #include "main/macros.h"
