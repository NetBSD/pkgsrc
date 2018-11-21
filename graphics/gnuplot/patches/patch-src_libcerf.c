$NetBSD: patch-src_libcerf.c,v 1.1 2018/11/21 17:12:06 adam Exp $

Re-order includes to avoid buidling problems.

--- src/libcerf.c.orig	2018-11-21 16:52:31.000000000 +0000
+++ src/libcerf.c
@@ -12,9 +12,8 @@
 #include "syscfg.h"
 #ifdef HAVE_LIBCERF
 #include <complex.h>	/* C99 _Complex */
-#include <cerf.h>	/* libcerf library header */
-
 #include "eval.h"
+#include <cerf.h>	/* libcerf library header */
 #include "stdfn.h"	/* for not_a_number */
 #include "util.h"	/* for int_error() */
 #include "libcerf.h"	/* our own prototypes */
