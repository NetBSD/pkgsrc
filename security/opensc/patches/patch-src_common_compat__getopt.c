$NetBSD: patch-src_common_compat__getopt.c,v 1.1 2012/11/30 14:44:35 gdt Exp $

See comment in patch-src_common_compat__getopt.h.

--- src/common/compat_getopt.c.orig	2011-07-05 11:28:53.000000000 +0000
+++ src/common/compat_getopt.c
@@ -25,7 +25,7 @@
 
 #include "config.h"
 
-#if ! ( defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) && defined(HAVE_GETOPT_LONG_ONLY) )
+#if ! ( defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) )
 
 #include <sys/types.h>
 #include <stdlib.h>
