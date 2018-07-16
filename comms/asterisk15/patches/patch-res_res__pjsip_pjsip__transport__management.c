$NetBSD: patch-res_res__pjsip_pjsip__transport__management.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_transport_management.c.orig	2018-06-20 15:03:44.845962982 +0000
+++ res/res_pjsip/pjsip_transport_management.c
@@ -20,12 +20,13 @@
 
 #include <signal.h>
 
+#include "asterisk/module.h"
+#include "asterisk/astobj2.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/module.h"
-#include "asterisk/astobj2.h"
 #include "include/res_pjsip_private.h"
 
 /*! \brief Number of buckets for monitored transports */
