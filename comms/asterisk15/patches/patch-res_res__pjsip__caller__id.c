$NetBSD: patch-res_res__pjsip__caller__id.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_caller_id.c.orig	2018-06-20 14:54:36.848214785 +0000
+++ res/res_pjsip_caller_id.c
@@ -25,14 +25,15 @@
 
 #include "asterisk.h"
 
+#include "asterisk/channel.h"
+#include "asterisk/module.h"
+#include "asterisk/callerid.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/channel.h"
-#include "asterisk/module.h"
-#include "asterisk/callerid.h"
 
 /*!
  * \internal
