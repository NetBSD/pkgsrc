$NetBSD: patch-funcs_func__pjsip__aor.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- funcs/func_pjsip_aor.c.orig	2018-06-20 14:41:48.304859278 +0000
+++ funcs/func_pjsip_aor.c
@@ -34,13 +34,14 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjlib.h>
-
 #include "asterisk/app.h"
 #include "asterisk/pbx.h"
 #include "asterisk/module.h"
 #include "asterisk/sorcery.h"
+
+#include <pjsip.h>
+#include <pjlib.h>
+
 #include "asterisk/res_pjsip.h"
 
 /*** DOCUMENTATION
