$NetBSD: patch-res_res__pjsip__header__funcs.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_header_funcs.c.orig	2018-06-20 14:59:36.015809914 +0000
+++ res/res_pjsip_header_funcs.c
@@ -25,17 +25,18 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_session.h"
 #include "asterisk/channel.h"
 #include "asterisk/pbx.h"
 #include "asterisk/app.h"
 #include "asterisk/module.h"
 #include "asterisk/utils.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_session.h"
+
 /*** DOCUMENTATION
 	<function name="PJSIP_HEADER" language="en_US">
 		<synopsis>
