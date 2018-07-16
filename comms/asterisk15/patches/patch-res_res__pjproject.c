$NetBSD: patch-res_res__pjproject.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjproject.c.orig	2018-06-20 14:49:55.032949063 +0000
+++ res/res_pjproject.c
@@ -99,18 +99,19 @@
 #include "asterisk.h"
 
 #include <stdarg.h>
-#include <pjlib.h>
-#include <pjsip.h>
-#include <pj/log.h>
-
 #include "asterisk/options.h"
 #include "asterisk/logger.h"
 #include "asterisk/module.h"
 #include "asterisk/cli.h"
-#include "asterisk/res_pjproject.h"
 #include "asterisk/vector.h"
 #include "asterisk/sorcery.h"
 
+#include <pjlib.h>
+#include <pjsip.h>
+#include <pj/log.h>
+
+#include "asterisk/res_pjproject.h"
+
 static struct ast_sorcery *pjproject_sorcery;
 static pj_log_func *log_cb_orig;
 static unsigned decor_orig;
