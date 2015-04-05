$NetBSD: patch-src_mesa_drivers_dri_common_dri__util.h,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/common/dri_util.h.orig	2011-07-09 01:31:41.000000000 +0000
+++ src/mesa/drivers/dri/common/dri_util.h
@@ -58,6 +58,10 @@
 
 #define GLX_BAD_CONTEXT                    5
 
+#define u_int64_t uint64_t
+#define u_int32_t uint32_t
+#define u_int8_t uint8_t
+
 typedef struct __DRIswapInfoRec        __DRIswapInfo;
 
 /**
