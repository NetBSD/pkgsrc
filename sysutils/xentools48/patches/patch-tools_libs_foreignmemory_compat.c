$NetBSD: patch-tools_libs_foreignmemory_compat.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/libs/foreignmemory/compat.c.orig	2017-03-24 18:42:26.000000000 +0100
+++ tools/libs/foreignmemory/compat.c	2017-03-24 18:41:44.000000000 +0100
@@ -20,6 +20,9 @@
 #endif
 
 #include "private.h"
+#include <stdlib.h>
+#include <errno.h>
+#include <string.h>
 
 void *osdep_xenforeignmemory_map(xenforeignmemory_handle *fmem,
                                  uint32_t dom, int prot, size_t num,
