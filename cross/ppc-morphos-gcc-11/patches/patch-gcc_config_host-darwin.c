$NetBSD: patch-gcc_config_host-darwin.c,v 1.1 2022/10/17 13:25:31 js Exp $

Add host hooks to allow hosting on Darwin/aarch64.
The patch is done differently from the upstream fix in order to be small.
Delete this patch when updating to GCC 12 or later.

--- gcc/config/host-darwin.c.orig	2020-07-23 06:35:17.000000000 +0000
+++ gcc/config/host-darwin.c
@@ -75,3 +75,9 @@ darwin_gt_pch_use_address (void *addr, s
 
   return ret;
 }
+
+#if defined(__aarch64__)
+#include "hosthooks.h"
+#include "hosthooks-def.h"
+const struct host_hooks host_hooks = HOST_HOOKS_INITIALIZER;
+#endif
