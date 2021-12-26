$NetBSD: patch-argp_argp-xinl.c,v 1.1 2021/12/26 23:54:01 nros Exp $

* defining __OPTIMIZE__ to nothing causes ssp.h on NetBSD
  to crash use __ARGP_OPTIMIZE__ instead to avoid conflict

--- argp/argp-xinl.c.orig	2021-12-26 22:35:33.786126632 +0000
+++ argp/argp-xinl.c
@@ -23,8 +23,8 @@
 #endif
 
 #define ARGP_EI
-#undef __OPTIMIZE__
-#define __OPTIMIZE__
+#undef __ARGP_OPTIMIZE__
+#define __ARGP_OPTIMIZE__
 #include "argp.h"
 
 /* Add weak aliases.  */
