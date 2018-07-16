$NetBSD: patch-res_res__pjsip__authenticator__digest.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_authenticator_digest.c.orig	2018-06-20 15:24:04.208176916 +0000
+++ res/res_pjsip_authenticator_digest.c
@@ -18,13 +18,14 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/logger.h"
 #include "asterisk/module.h"
 #include "asterisk/strings.h"
 
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
+
 /*** MODULEINFO
 	<depend>pjproject</depend>
 	<depend>res_pjsip</depend>
