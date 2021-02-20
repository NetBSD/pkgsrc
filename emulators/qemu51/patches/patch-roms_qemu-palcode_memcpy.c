$NetBSD: patch-roms_qemu-palcode_memcpy.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Include local header file for prototypes.

--- roms/qemu-palcode/memcpy.c.orig	2020-10-04 16:22:55.342263484 +0000
+++ roms/qemu-palcode/memcpy.c	2020-10-04 16:23:41.685256308 +0000
@@ -8,7 +8,7 @@
  * This is a reasonably optimized memcpy() routine.
  */
 
-#include <string.h>
+#include "protos.h"
 
 /*
  * Note that the C code is written to be optimized into good assembly. However,
