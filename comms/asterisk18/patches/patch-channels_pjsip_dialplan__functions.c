$NetBSD: patch-channels_pjsip_dialplan__functions.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- channels/pjsip/dialplan_functions.c.orig	2018-06-20 14:39:31.934736437 +0000
+++ channels/pjsip/dialplan_functions.c
@@ -450,10 +450,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjlib.h>
-#include <pjsip_ua.h>
-
 #include "asterisk/astobj2.h"
 #include "asterisk/module.h"
 #include "asterisk/acl.h"
@@ -463,10 +459,15 @@
 #include "asterisk/format.h"
 #include "asterisk/dsp.h"
 #include "asterisk/pbx.h"
+#include "include/dialplan_functions.h"
+
+#include <pjsip.h>
+#include <pjlib.h>
+#include <pjsip_ua.h>
+
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 #include "include/chan_pjsip.h"
-#include "include/dialplan_functions.h"
 
 /*!
  * \brief String representations of the T.38 state enum
