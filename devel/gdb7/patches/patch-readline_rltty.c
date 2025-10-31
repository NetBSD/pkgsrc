$NetBSD: patch-readline_rltty.c,v 1.1 2025/10/31 15:05:37 ryoon Exp $

* Fix GCC 14 build.

--- readline/rltty.c.orig	2025-10-21 10:40:10.841908050 +0000
+++ readline/rltty.c
@@ -37,9 +37,7 @@
 
 #include "rldefs.h"
 
-#if defined (GWINSZ_IN_SYS_IOCTL)
-#  include <sys/ioctl.h>
-#endif /* GWINSZ_IN_SYS_IOCTL */
+#include <sys/ioctl.h>
 
 #include "rltty.h"
 #include "readline.h"
