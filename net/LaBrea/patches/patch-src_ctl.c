$NetBSD: patch-src_ctl.c,v 1.1 2012/11/16 20:10:20 joerg Exp $

--- src/ctl.c.orig	2003-09-12 21:23:39.000000000 +0000
+++ src/ctl.c
@@ -39,19 +39,19 @@
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
 #ifdef HAVE_WINDOWS_H
 #include <windows.h>
 #endif
 
-#include "labrea.h"
-#include "bget.h"
-#include "pkt.h"
-#include "utils.h"
-#include "lbio.h"
-#include "ctl.h"
+#include "../inc/labrea.h"
+#include "../inc/bget.h"
+#include "../inc/pkt.h"
+#include "../inc/utils.h"
+#include "../inc/lbio.h"
+#include "../inc/ctl.h"
 
 
 /*
