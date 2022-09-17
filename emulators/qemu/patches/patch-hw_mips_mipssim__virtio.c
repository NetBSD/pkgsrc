$NetBSD: patch-hw_mips_mipssim__virtio.c,v 1.1 2022/09/17 09:54:56 tnn Exp $

Fix build error. mipssim_virtio.c is removed in master.

--- hw/mips/mipssim_virtio.c.orig	2022-09-07 17:53:18.000000000 +0000
+++ hw/mips/mipssim_virtio.c
@@ -33,7 +33,6 @@
 
 #include "qemu/osdep.h"
 #include "qapi/error.h"
-#include "qemu-common.h"
 #include "cpu.h"
 #include "hw/mips/mips.h"
 #include "hw/mips/cpudevs.h"
