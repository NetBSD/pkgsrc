$NetBSD: patch-res_res__pjsip__acl.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_acl.c.orig	2018-06-20 14:56:24.968342681 +0000
+++ res/res_pjsip_acl.c
@@ -24,14 +24,15 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/module.h"
 #include "asterisk/logger.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/acl.h"
 
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
+
 /*** DOCUMENTATION
 	<configInfo name="res_pjsip_acl" language="en_US">
 		<synopsis>SIP ACL module</synopsis>
