$NetBSD: patch-funcs_func__pjsip__endpoint.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- funcs/func_pjsip_endpoint.c.orig	2018-06-20 14:41:38.307201390 +0000
+++ funcs/func_pjsip_endpoint.c
@@ -34,14 +34,15 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjlib.h>
-
 #include "asterisk/app.h"
 #include "asterisk/pbx.h"
 #include "asterisk/module.h"
 #include "asterisk/channel.h"
 #include "asterisk/sorcery.h"
+
+#include <pjsip.h>
+#include <pjlib.h>
+
 #include "asterisk/res_pjsip.h"
 
 /*** DOCUMENTATION
