$NetBSD: patch-src_pkt__handler.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/pkt_handler.c.orig	2003-09-12 21:23:39.000000000 +0000
+++ src/pkt_handler.c
@@ -34,16 +34,16 @@
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
-#include "labrea.h"
-#include "pkt.h"
-#include "bget.h"
-#include "ctl.h"
-#include "lbio.h"
-#include "utils.h"
-#include "pkt_handler.h"
+#include "../inc/labrea.h"
+#include "../inc/pkt.h"
+#include "../inc/bget.h"
+#include "../inc/ctl.h"
+#include "../inc/lbio.h"
+#include "../inc/utils.h"
+#include "../inc/pkt_handler.h"
 
 
 /*
