$NetBSD: patch-res_res__pjsip__refer.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_refer.c.orig	2018-06-20 14:53:06.998187075 +0000
+++ res/res_pjsip_refer.c
@@ -25,11 +25,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_session.h"
 #include "asterisk/module.h"
 #include "asterisk/pbx.h"
 #include "asterisk/taskprocessor.h"
@@ -39,6 +34,12 @@
 #include "asterisk/stasis_channels.h"
 #include "asterisk/causes.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_session.h"
+
 /*! \brief REFER Progress structure */
 struct refer_progress {
 	/*! \brief Subscription to provide updates on */
