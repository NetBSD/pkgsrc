$NetBSD: patch-plugins__check_swap.c,v 1.1 2012/07/25 12:01:55 fhajny Exp $

Disable large file support when building 32bit on SunOS.
--- plugins/check_swap.c.orig	2010-07-27 20:47:16.000000000 +0000
+++ plugins/check_swap.c
@@ -35,6 +35,10 @@ const char *email = "nagiosplug-devel@li
 #include "popen.h"
 #include "utils.h"
 
+#if defined(__sun) && !defined(_LP64) && _FILE_OFFSET_BITS == 64
+#undef _FILE_OFFSET_BITS
+#endif
+
 #ifdef HAVE_DECL_SWAPCTL
 # ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
