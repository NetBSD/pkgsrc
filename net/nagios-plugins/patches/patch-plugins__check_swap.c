$NetBSD: patch-plugins__check_swap.c,v 1.2 2015/04/03 17:50:27 rodent Exp $

Disable large file support when building 32bit on SunOS.
--- plugins/check_swap.c.orig	2014-04-15 22:19:03.000000000 +0000
+++ plugins/check_swap.c
@@ -35,6 +35,10 @@ const char *email = "devel@nagios-plugin
 #include "popen.h"
 #include "utils.h"
 
+#if defined(__sun) && !defined(_LP64) && _FILE_OFFSET_BITS == 64
+#undef _FILE_OFFSET_BITS
+#endif
+
 #ifdef HAVE_DECL_SWAPCTL
 # ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
