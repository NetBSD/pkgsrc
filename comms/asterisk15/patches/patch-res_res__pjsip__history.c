$NetBSD: patch-res_res__pjsip__history.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_history.c.orig	2018-06-20 14:51:30.138834951 +0000
+++ res/res_pjsip_history.c
@@ -31,17 +31,18 @@
  ***/
 
 #include "asterisk.h"
-
-#include <pjsip.h>
 #include <regex.h>
 
-#include "asterisk/res_pjsip.h"
 #include "asterisk/module.h"
 #include "asterisk/logger.h"
 #include "asterisk/cli.h"
 #include "asterisk/netsock2.h"
 #include "asterisk/vector.h"
 #include "asterisk/lock.h"
+
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjproject.h"
 
 #define HISTORY_INITIAL_SIZE 256
