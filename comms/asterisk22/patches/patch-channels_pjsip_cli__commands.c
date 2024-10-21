$NetBSD: patch-channels_pjsip_cli__commands.c,v 1.1 2024/10/21 05:12:45 jnemeth Exp $

--- channels/pjsip/cli_commands.c.orig	2018-06-20 14:37:54.485779459 +0000
+++ channels/pjsip/cli_commands.c
@@ -26,20 +26,21 @@
 
 #include "asterisk.h"
 
+#include "asterisk/astobj2.h"
+#include "asterisk/channel.h"
+#include "asterisk/format.h"
+#include "asterisk/stasis.h"
+#include "asterisk/time.h"
+#include "include/cli_functions.h"
+
 #include <pjsip.h>
 #include <pjlib.h>
 #include <pjsip_ua.h>
 
-#include "asterisk/astobj2.h"
-#include "asterisk/channel.h"
-#include "asterisk/format.h"
+#include "include/chan_pjsip.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 #include "asterisk/res_pjsip_cli.h"
-#include "asterisk/stasis.h"
-#include "asterisk/time.h"
-#include "include/chan_pjsip.h"
-#include "include/cli_functions.h"
 
 
 static int cli_channel_iterate(void *endpoint, ao2_callback_fn callback, void *arg)
