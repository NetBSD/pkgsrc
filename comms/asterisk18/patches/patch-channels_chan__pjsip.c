$NetBSD: patch-channels_chan__pjsip.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- channels/chan_pjsip.c.orig	2019-09-05 13:09:20.000000000 +0000
+++ channels/chan_pjsip.c
@@ -34,10 +34,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-#include <pjlib.h>
-
 #include "asterisk/lock.h"
 #include "asterisk/channel.h"
 #include "asterisk/module.h"
@@ -63,10 +59,14 @@
 #include "asterisk/test.h"
 #include "asterisk/message.h"
 
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_session.h"
 #include "asterisk/stream.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_session.h"
 #include "pjsip/include/chan_pjsip.h"
 #include "pjsip/include/dialplan_functions.h"
 #include "pjsip/include/cli_functions.h"
