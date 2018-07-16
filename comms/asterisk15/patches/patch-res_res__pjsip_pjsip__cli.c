$NetBSD: patch-res_res__pjsip_pjsip__cli.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_cli.c.orig	2018-06-20 15:02:40.104650162 +0000
+++ res/res_pjsip/pjsip_cli.c
@@ -18,12 +18,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-
-#include "asterisk/res_pjsip.h"
-#include "include/res_pjsip_private.h"
-#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/acl.h"
 #include "asterisk/cli.h"
 #include "asterisk/astobj2.h"
@@ -31,6 +25,13 @@
 #include "asterisk/utils.h"
 #include "asterisk/sorcery.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
+#include "asterisk/res_pjsip.h"
+#include "include/res_pjsip_private.h"
+#include "asterisk/res_pjsip_cli.h"
+
 static struct ao2_container *formatter_registry;
 
 int ast_sip_cli_print_sorcery_objectset(void *obj, void *arg, int flags)
