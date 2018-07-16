$NetBSD: patch-channels_chan__pjsip.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- channels/chan_pjsip.c.orig	2018-06-20 14:36:49.919764716 +0000
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
@@ -62,10 +58,14 @@
 #include "asterisk/pickup.h"
 #include "asterisk/test.h"
 
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
