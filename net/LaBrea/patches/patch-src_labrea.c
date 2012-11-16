$NetBSD: patch-src_labrea.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/labrea.c.orig	2003-09-12 21:23:39.000000000 +0000
+++ src/labrea.c
@@ -42,15 +42,15 @@
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
 
-#include "labrea.h"
-#include "ctl.h"
-#include "utils.h"
-#include "lbio.h"
-#include "pkt_handler.h"
+#include "../inc/labrea.h"
+#include "../inc/ctl.h"
+#include "../inc/utils.h"
+#include "../inc/lbio.h"
+#include "../inc/pkt_handler.h"
 
 /* Definitions of main control structures */
 io_t io;
