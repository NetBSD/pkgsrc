$NetBSD: patch-res_res__pjsip_pjsip__options.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_options.c.orig	2018-06-20 15:12:53.179204973 +0000
+++ res/res_pjsip/pjsip_options.c
@@ -18,11 +18,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-#include <pjlib.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/channel.h"
 #include "asterisk/pbx.h"
 #include "asterisk/astobj2.h"
@@ -30,9 +25,15 @@
 #include "asterisk/time.h"
 #include "asterisk/test.h"
 #include "asterisk/statsd.h"
-#include "include/res_pjsip_private.h"
 #include "asterisk/taskprocessor.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
+#include "include/res_pjsip_private.h"
+
 #define DEFAULT_LANGUAGE "en"
 #define DEFAULT_ENCODING "text/plain"
 #define QUALIFIED_BUCKETS 211
