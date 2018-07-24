$NetBSD: patch-tools_libs_foreignmemory_compat.c,v 1.1 2018/07/24 13:40:11 bouyer Exp $

--- ./tools/libs/foreignmemory/compat.c.orig	2018-04-17 19:21:31.000000000 +0200
+++ ./tools/libs/foreignmemory/compat.c	2018-04-23 17:05:48.000000000 +0200
@@ -19,6 +19,9 @@
 #error Please implement osdep_xenforeignmemory_map directly for new ports.
 #endif
 
+#include <stdlib.h>
+#include <errno.h>
+#include <string.h>
 #include "private.h"
 
 void *osdep_xenforeignmemory_map(xenforeignmemory_handle *fmem, uint32_t dom,
