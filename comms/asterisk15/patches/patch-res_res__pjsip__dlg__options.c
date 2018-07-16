$NetBSD: patch-res_res__pjsip__dlg__options.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_dlg_options.c.orig	2018-06-20 14:45:17.495724166 +0000
+++ res/res_pjsip_dlg_options.c
@@ -25,11 +25,12 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 #include <pjlib.h>
 
-#include "asterisk/module.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 
