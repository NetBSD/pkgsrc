$NetBSD: patch-src_gallium_drivers_vc4_vc4__bufmgr.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Patch from FreeBSD ports graphics/mesa-dri 17.1.0

# define ETIME as ETIMEOUT same as in intel driver

--- src/gallium/drivers/vc4/vc4_bufmgr.c.orig	2017-05-25 07:13:13.000000000 +0000
+++ src/gallium/drivers/vc4/vc4_bufmgr.c
@@ -27,6 +27,9 @@
 #include <fcntl.h>
 #include <xf86drm.h>
 #include <xf86drmMode.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 #include "util/u_hash_table.h"
 #include "util/u_memory.h"
