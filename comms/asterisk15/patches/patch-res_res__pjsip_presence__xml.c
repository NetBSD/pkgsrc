$NetBSD: patch-res_res__pjsip_presence__xml.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/presence_xml.c.orig	2018-06-20 15:06:56.336281107 +0000
+++ res/res_pjsip/presence_xml.c
@@ -18,12 +18,13 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/pbx.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 #include <pjlib.h>
 
-#include "asterisk/module.h"
-#include "asterisk/pbx.h"
 #include "asterisk/res_pjsip_presence_xml.h"
 
 void ast_sip_sanitize_xml(const char *input, char *output, size_t len)
