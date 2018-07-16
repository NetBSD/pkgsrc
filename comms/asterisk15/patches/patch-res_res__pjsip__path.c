$NetBSD: patch-res_res__pjsip__path.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_path.c.orig	2018-06-20 14:52:49.712903058 +0000
+++ res/res_pjsip_path.c
@@ -23,14 +23,14 @@
  ***/
 
 #include "asterisk.h"
+#include "asterisk/module.h"
+#include "asterisk/strings.h"
 
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
-#include "asterisk/strings.h"
 
 static const pj_str_t PATH_NAME = { "Path", 4 };
 static pj_str_t PATH_SUPPORTED_NAME = { "path", 4 };
