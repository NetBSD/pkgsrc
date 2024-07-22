$NetBSD: patch-newlib_libc_posix_collate.c,v 1.1 2024/07/22 20:01:50 tnn Exp $

work around a problem where PATH_MAX is undefined

--- newlib/libc/posix/collate.c.orig	2024-07-20 16:18:23.269162402 +0000
+++ newlib/libc/posix/collate.c
@@ -26,6 +26,7 @@
  */
 
 #include <sys/cdefs.h>
+#include "../include/limits.h"
 
 #include "namespace.h"
 #include "rune.h"
