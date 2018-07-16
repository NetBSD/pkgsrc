$NetBSD: patch-res_res__pjsip__sdp__rtp.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_sdp_rtp.c.orig	2018-06-20 14:44:19.523907244 +0000
+++ res/res_pjsip_sdp_rtp.c
@@ -33,11 +33,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-#include <pjmedia.h>
-#include <pjlib.h>
-
 #include "asterisk/utils.h"
 #include "asterisk/module.h"
 #include "asterisk/format.h"
@@ -54,6 +49,11 @@
 #include "asterisk/stream.h"
 #include "asterisk/format_cache.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+#include <pjmedia.h>
+#include <pjlib.h>
+
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 
