$NetBSD: patch-src_utils.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/utils.c.orig	2012-11-16 11:44:53.000000000 +0000
+++ src/utils.c
@@ -48,7 +48,7 @@
 #ifdef HAVE_SYSLOG_H 
 #include <syslog.h>
 #else
-#include "syslog.h"
+#include "../inc/syslog.h"
 #endif
 
 #include <errno.h>
@@ -56,7 +56,7 @@
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
 #ifdef HAVE_WINSOCK_H
@@ -67,13 +67,13 @@
 #include <windows.h>
 #endif
 
-#include "bget.h"
-#include "pkt.h"
-#include "labrea.h"
-#include "pcaputil.h"
-#include "ctl.h"
-#include "lbio.h"
-#include "utils.h"
+#include "../inc/bget.h"
+#include "../inc/pkt.h"
+#include "../inc/labrea.h"
+#include "../inc/pcaputil.h"
+#include "../inc/ctl.h"
+#include "../inc/lbio.h"
+#include "../inc/utils.h"
 
 
 void
