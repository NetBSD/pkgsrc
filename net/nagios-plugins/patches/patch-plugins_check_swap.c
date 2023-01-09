$NetBSD: patch-plugins_check_swap.c,v 1.1 2023/01/09 00:28:41 sekiya Exp $

Disable large file support when building 32bit on SunOS.

--- plugins/check_swap.c.orig	2019-12-05 06:53:08.000000000 +0900
+++ plugins/check_swap.c	2023-01-09 08:53:18.345470217 +0900
@@ -35,6 +35,10 @@
 #include "popen.h"
 #include "utils.h"
 
+#if defined(__sun) && !defined(_LP64) && _FILE_OFFSET_BITS == 64
+#undef _FILE_OFFSET_BITS
+#endif
+
 #ifdef HAVE_DECL_SWAPCTL
 # ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
