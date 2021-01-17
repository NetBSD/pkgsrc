$NetBSD: patch-res_res__pjsip_pjsip__options.c,v 1.2 2021/01/17 08:32:40 jnemeth Exp $

--- res/res_pjsip/pjsip_options.c.orig	2019-09-05 13:09:20.000000000 +0000
+++ res/res_pjsip/pjsip_options.c
@@ -19,11 +19,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-#include <pjlib.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/channel.h"
 #include "asterisk/pbx.h"
 #include "asterisk/astobj2.h"
@@ -31,10 +26,16 @@
 #include "asterisk/time.h"
 #include "asterisk/test.h"
 #include "asterisk/statsd.h"
-#include "include/res_pjsip_private.h"
 #include "asterisk/taskprocessor.h"
 #include "asterisk/threadpool.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
+#include "include/res_pjsip_private.h"
+
 /*
  * This implementation for OPTIONS support is based around the idea
  * that realistically an AOR generally has very few contacts and is
