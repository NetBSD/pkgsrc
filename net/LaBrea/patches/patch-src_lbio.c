$NetBSD: patch-src_lbio.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/lbio.c.orig	2003-09-12 21:23:39.000000000 +0000
+++ src/lbio.c
@@ -33,20 +33,20 @@
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
 
-#include "labrea.h"
-#include "bget.h"
-#include "pkt.h"
-#include "ctl.h"
-#include "utils.h"
-#include "pcaputil.h"
-#include "lbio.h"
+#include "../inc/labrea.h"
+#include "../inc/bget.h"
+#include "../inc/pkt.h"
+#include "../inc/ctl.h"
+#include "../inc/utils.h"
+#include "../inc/pcaputil.h"
+#include "../inc/lbio.h"
 
 #ifdef WIN32
 /* has to be here to avoid compile errors with bpf structs */
