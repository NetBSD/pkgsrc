$NetBSD: patch-res_res__pjsip_pjsip__session.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_session.c.orig	2018-06-20 15:05:52.774557946 +0000
+++ res/res_pjsip/pjsip_session.c
@@ -18,6 +18,10 @@
 
 #include "asterisk.h"
 
+#include "asterisk/linkedlists.h"
+#include "asterisk/lock.h"
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 #include <pjlib.h>
@@ -25,9 +29,6 @@
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 #include "include/res_pjsip_private.h"
-#include "asterisk/linkedlists.h"
-#include "asterisk/lock.h"
-#include "asterisk/module.h"
 
 
 AST_RWLIST_HEAD_STATIC(session_supplements, ast_sip_session_supplement);
