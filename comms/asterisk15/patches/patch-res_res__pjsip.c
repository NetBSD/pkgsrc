$NetBSD: patch-res_res__pjsip.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip.c.orig	2018-06-20 15:00:27.990234837 +0000
+++ res/res_pjsip.c
@@ -18,16 +18,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-/* Needed for SUBSCRIBE, NOTIFY, and PUBLISH method definitions */
-#include <pjsip_simple.h>
-#include <pjsip/sip_transaction.h>
-#include <pj/timer.h>
-#include <pjlib.h>
-#include <pjmedia/errno.h>
-
-#include "asterisk/res_pjsip.h"
-#include "res_pjsip/include/res_pjsip_private.h"
 #include "asterisk/linkedlists.h"
 #include "asterisk/logger.h"
 #include "asterisk/lock.h"
@@ -40,8 +30,19 @@
 #include "asterisk/sorcery.h"
 #include "asterisk/file.h"
 #include "asterisk/cli.h"
-#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/test.h"
+
+#include <pjsip.h>
+/* Needed for SUBSCRIBE, NOTIFY, and PUBLISH method definitions */
+#include <pjsip_simple.h>
+#include <pjsip/sip_transaction.h>
+#include <pj/timer.h>
+#include <pjlib.h>
+#include <pjmedia/errno.h>
+
+#include "asterisk/res_pjsip.h"
+#include "res_pjsip/include/res_pjsip_private.h"
+#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/res_pjsip_presence_xml.h"
 #include "asterisk/res_pjproject.h"
 
