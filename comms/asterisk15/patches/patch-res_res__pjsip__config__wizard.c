$NetBSD: patch-res_res__pjsip__config__wizard.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_config_wizard.c.orig	2018-06-20 15:24:53.691223999 +0000
+++ res/res_pjsip_config_wizard.c
@@ -40,16 +40,18 @@
 #include "asterisk.h"
 
 #include <regex.h>
-#include <pjsip.h>
 
 #include "asterisk/astobj2.h"
 #include "asterisk/cli.h"
-#include "asterisk/res_pjsip.h"
 #include "asterisk/module.h"
 #include "asterisk/pbx.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/vector.h"
 
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
+
 /*** DOCUMENTATION
 	<configInfo name="res_pjsip_config_wizard" language="en_US">
 		<synopsis>Module that privides simple configuration wizard capabilities.</synopsis>
