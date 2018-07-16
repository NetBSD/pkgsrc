$NetBSD: patch-res_res__pjsip__t38.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_t38.c.orig	2018-06-20 15:15:02.160803849 +0000
+++ res/res_pjsip_t38.c
@@ -32,11 +32,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-#include <pjmedia.h>
-#include <pjlib.h>
-
 #include "asterisk/utils.h"
 #include "asterisk/module.h"
 #include "asterisk/udptl.h"
@@ -46,6 +41,11 @@
 #include "asterisk/stream.h"
 #include "asterisk/format_cache.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+#include <pjmedia.h>
+#include <pjlib.h>
+
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 
