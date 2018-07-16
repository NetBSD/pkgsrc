$NetBSD: patch-res_res__pjsip__notify.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_notify.c.orig	2018-06-20 15:18:42.604587100 +0000
+++ res/res_pjsip_notify.c
@@ -24,17 +24,18 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-
 #include "asterisk/cli.h"
 #include "asterisk/config.h"
 #include "asterisk/manager.h"
 #include "asterisk/module.h"
 #include "asterisk/pbx.h"
+#include "asterisk/sorcery.h"
+
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/sorcery.h"
 
 /*** DOCUMENTATION
 	<manager name="PJSIPNotify" language="en_US">
