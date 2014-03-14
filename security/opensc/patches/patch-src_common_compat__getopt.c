$NetBSD: patch-src_common_compat__getopt.c,v 1.2 2014/03/14 20:49:56 gdt Exp $

See comment in patch-src_common_compat__getopt.h.

--- src/common/compat_getopt.c.orig	2012-12-04 14:43:40.000000000 +0000
+++ src/common/compat_getopt.c
@@ -25,7 +25,7 @@
 
 #include "config.h"
 
-#if ! ( defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) && defined(HAVE_GETOPT_LONG_ONLY) )
+#if ! ( defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG) )
 
 #include <sys/types.h>
 #include <stdlib.h>
