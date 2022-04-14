$NetBSD: patch-newlib_libc_posix_collate.c,v 1.1 2022/04/14 00:50:00 tnn Exp $

work around a problem where PATH_MAX is undefined

--- newlib/libc/posix/collate.c.orig	2022-03-31 06:25:20.000000000 +0000
+++ newlib/libc/posix/collate.c
@@ -26,6 +26,7 @@
  */
 
 #include <sys/cdefs.h>
+#include "../include/limits.h"
 
 #include "namespace.h"
 #include <rune.h>
