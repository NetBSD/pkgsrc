$NetBSD: patch-src_syslog.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/syslog.c.orig	2003-09-09 20:55:03.000000000 +0000
+++ src/syslog.c
@@ -43,14 +43,14 @@
 #ifdef HAVE_ERR_H
 #include <err.h>
 #else
-#include "err.h"
+#include "../inc/err.h"
 #endif
 
-#include "syslog_name.h"
-#include "syslog.h"
-#include "utils.h"
-#include "labrea.h"
-#include "ctl.h"
+#include "../inc/syslog_name.h"
+#include "../inc/syslog.h"
+#include "../inc/utils.h"
+#include "../inc/labrea.h"
+#include "../inc/ctl.h"
 
 
 #define TBUF_LEN        2048
