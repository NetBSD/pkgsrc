$NetBSD: patch-src_mesa_drivers_dri_common_mmio.h,v 1.1 2013/05/16 05:22:02 richard Exp $

--- src/mesa/drivers/dri/common/mmio.h.orig	2010-02-05 00:10:40.000000000 +0000
+++ src/mesa/drivers/dri/common/mmio.h
@@ -34,6 +34,7 @@
 #define MMIO_H
 
 #include "main/glheader.h"
+#include "dri_util.h"
 
 #if defined( __powerpc__ )
 
