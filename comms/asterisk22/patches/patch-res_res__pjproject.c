$NetBSD: patch-res_res__pjproject.c,v 1.2 2026/04/13 02:50:22 jnemeth Exp $

--- res/res_pjproject.c.orig	2026-04-09 16:24:26.000000000 +0000
+++ res/res_pjproject.c
@@ -131,19 +131,21 @@
 #include "asterisk.h"
 
 #include <stdarg.h>
-#include <pjlib.h>
-#include <pjsip.h>
-#include <pj/log.h>
 
 #include "asterisk/options.h"
 #include "asterisk/logger.h"
 #include "asterisk/module.h"
 #include "asterisk/cli.h"
-#include "asterisk/res_pjproject.h"
 #include "asterisk/vector.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/test.h"
 #include "asterisk/netsock2.h"
+
+#include <pjlib.h>
+#include <pjsip.h>
+#include <pj/log.h>
+
+#include "asterisk/res_pjproject.h"
 
 static struct ast_sorcery *pjproject_sorcery;
 static pj_log_func *log_cb_orig;
