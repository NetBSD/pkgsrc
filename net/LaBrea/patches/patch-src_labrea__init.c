$NetBSD: patch-src_labrea__init.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/labrea_init.c.orig	2003-09-12 21:23:39.000000000 +0000
+++ src/labrea_init.c
@@ -38,20 +38,20 @@
 #ifdef HAVE_GETOPT_H
 #include <getopt.h>
 #else
-#include "getopt.h"
+#include "../inc/getopt.h"
 #endif
 
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
-#include "labrea.h"
-#include "pcaputil.h"
-#include "ctl.h"
-#include "utils.h"
-#include "lbio.h"
+#include "../inc/labrea.h"
+#include "../inc/pcaputil.h"
+#include "../inc/ctl.h"
+#include "../inc/utils.h"
+#include "../inc/lbio.h"
 
 int input_error = FALSE;	/* True if errors on input */
 
