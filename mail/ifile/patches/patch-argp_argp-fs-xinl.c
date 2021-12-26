$NetBSD: patch-argp_argp-fs-xinl.c,v 1.1 2021/12/26 23:54:01 nros Exp $

* defining __OPTIMIZE__ to nothing causes ssp.h on NetBSD
  to crash use __ARGP_OPTIMIZE__ instead to avoid conflict

--- argp/argp-fs-xinl.c.orig	2021-12-26 22:34:56.922104884 +0000
+++ argp/argp-fs-xinl.c
@@ -23,8 +23,8 @@
 #endif
 
 #define ARGP_FS_EI
-#undef __OPTIMIZE__
-#define __OPTIMIZE__
+#undef __ARGP_OPTIMIZE__
+#define __ARGP_OPTIMIZE__
 #include "argp-fmtstream.h"
 
 /* Add weak aliases.  */
