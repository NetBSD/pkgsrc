$NetBSD: patch-res_res__pjsip__registrar.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_registrar.c.orig	2018-06-20 15:15:55.779062250 +0000
+++ res/res_pjsip_registrar.c
@@ -26,16 +26,18 @@
 #include "asterisk.h"
 
 #include <signal.h>
-#include <pjsip.h>
-#include <pjsip_ua.h>
 
-#include "asterisk/res_pjsip.h"
 #include "asterisk/module.h"
 #include "asterisk/paths.h"
 #include "asterisk/test.h"
 #include "asterisk/taskprocessor.h"
 #include "asterisk/manager.h"
 #include "asterisk/named_locks.h"
+
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
+#include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjproject.h"
 #include "res_pjsip/include/res_pjsip_private.h"
 
